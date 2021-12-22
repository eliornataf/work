from scraper_api import ScraperAPIClient
from bs4 import BeautifulSoup
from current_population_scraper import CurrentPopulationScraper
from historical_popultion_scraper import HistoricalPopulationScraper
from gender_population_scraper import GenderPopulationScraper

class ScrappingManager():
    """This class manages the differences scrapers for a given zip code in the US and returns its values"""

    def __init__(self, url, apikey):
        self._url = url
        self._apikey = apikey
        self._current_population_scraper = CurrentPopulationScraper()
        self._historical_popultion_scraper = HistoricalPopulationScraper()
        self._gender_population_scraper = GenderPopulationScraper()

    def _parse_zip_code_page_to_soup(self, zip_code):
        client = ScraperAPIClient(self._apikey)
        result = client.get(url=self._url + str(zip_code)).text
        return BeautifulSoup(result, "html.parser")

    def scrape(self, zip_code):
        soup = self._parse_zip_code_page_to_soup(zip_code)
        current_population = self._current_population_scraper.scrap(soup)
        historical_population = self._historical_popultion_scraper.scrap(soup)
        gender_population = self._gender_population_scraper.scrap(soup)
        return [current_population, historical_population, gender_population]



                
                




