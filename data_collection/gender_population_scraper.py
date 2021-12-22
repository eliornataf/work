from bs4 import BeautifulSoup

class GenderPopulationScraper():
    """This class scrapes and returns the US population value and percentage per gender for a given zip code"""

    def __init__(self):
        pass

    def _male_population_value(self, soup):
        try:
            return soup.find(attrs={"data-color": "#1f77b4"}).find_next_sibling().get_text()
        except:
            return None

    def _male_population_percentage(self, soup):
        try:
            return soup.find(attrs={"data-color": "#1f77b4"}).find_next_sibling().find_next_sibling().get_text()
        except:
            return None

    def _female_population_value(self, soup):
        try:
            return soup.find(attrs={"data-color": "#aec7e8"}).find_next_sibling().get_text()
        except:
            return None

    def _female_population_percentage(self, soup):
        try:
            return soup.find(attrs={"data-color": "#aec7e8"}).find_next_sibling().find_next_sibling().get_text()
        except:
            return None

    def _convert_to_dictionary(self, *args):
        return {"Male Population Value": args[0], "Male Population Peracentage": args[1], "Female Population Value": args[2], "Female Population Peracentage": args[3]}

    def scrap(self, soup):
        male_population_value = self._male_population_value(soup)
        male_population_percentage = self._male_population_percentage(soup)
        female_population_value = self._female_population_value(soup)
        female_population_percentage = self._female_population_percentage(soup)
        return self._convert_to_dictionary(male_population_value, male_population_percentage, female_population_value, female_population_percentage)
