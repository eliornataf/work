from bs4 import BeautifulSoup

class CurrentPopulationScraper():
    """This class scrapes and returns the US current population value for a given zip code"""

    def __init__(self):
        pass

    def _target_object(self, soup):
        return soup.find(class_="text-right")

    def _clean_data(self, string):
        return string.replace(",", "")
    
    def scrap(self, soup):
        target_object = self._target_object(soup)
        return self._clean_data(target_object.get_text()) if target_object else None 