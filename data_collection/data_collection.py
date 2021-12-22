from pandas import read_csv 
from threading import Lock
from concurrent.futures import ThreadPoolExecutor
from scrapping_manager import ScrappingManager
from serializer import Serializer

class DataCollection():
    """This class scrapes specified data for each US zip code and exports it to a pandas dataframe"""

    URL = "https://www.unitedstateszipcodes.org/"

    def __init__(self, csv_file, api_key):
        self._zip_codes = self._fetch_zip_codes_list(csv_file)
        self._scrapping_manager = ScrappingManager(self.URL, api_key)
        self._part_one_data_soultion = []
        self._part_two_data_soultion = []
        self._mutex_part_one_soultion = Lock()
        self._mutex_part_two_soultion = Lock()

    def _fetch_zip_codes_list(self, csv_file):
        df = read_csv(csv_file)
        return df['zip'].tolist()

    def _thread_function(self, zip_code):
        scrapped_data = self._scrapping_manager.scrape(zip_code)
        if scrapped_data:
            dictionaries = self._make_zip_code_dictionaries(zip_code, scrapped_data[0], scrapped_data[1], scrapped_data[2])
            self._add_dictionary_to_part_one_solution(dictionaries[0])
            self._add_dictionary_to_part_two_solution(dictionaries[1])

    def _make_zip_code_dictionaries(self, zip_code, current_population, historical_population, gender_population):
        zip_code_dictionary_part_one_soultion = {"Zip Code": zip_code, "Current Population": current_population}
        zip_code_dictionary_part_one_soultion.update(historical_population)

        zip_code_dictionary_part_two_soultion = {"Zip Code": zip_code, "Current Population": current_population}
        zip_code_dictionary_part_two_soultion.update(gender_population)

        return [zip_code_dictionary_part_one_soultion, zip_code_dictionary_part_two_soultion]

    def _add_dictionary_to_part_one_solution(self, dictionary):
        self._mutex_part_one_soultion.acquire()
        self._part_one_data_soultion.append(dictionary)
        self._mutex_part_one_soultion.release()

    def _add_dictionary_to_part_two_solution(self, dictionary):       
        self._mutex_part_two_soultion.acquire()
        self._part_two_data_soultion.append(dictionary)
        self._mutex_part_two_soultion.release()

    def execute(self):
        with ThreadPoolExecutor() as executor:
            executor.map(self._thread_function, self._zip_codes)

        Serializer(self._part_one_data_soultion, self._part_two_data_soultion).serialize()


