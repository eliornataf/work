from bs4 import BeautifulSoup

class HistoricalPopulationScraper():
    """This class scrapes and returns the US historic population value for a given zip code"""

    def __init__(self):
        pass

    def _target_data(self, soup):
        try:
            return soup.find(attrs={"src": "/shared-assets/nv.d3-1.8.1.min.cache_extend.1581627375.js"}).find_next_sibling().get_text()
        except:
            return None

    def _slice_data(self, string):
        from_index = string.index('"x')
        to_index = string.index("}]", from_index)
        return string[from_index:to_index:]

    def _split_string(self, string):
        return string.split("},{")

    def _convert_to_dictionary(self, list_data):
        dictionary = {row[4:8]: row[13:] for row in list_data}
        if len(dictionary) != 14:
            for year in range(2005, 2019):
                if not str(year) in dictionary:
                    dictionary[str(year)] = None
        return dictionary     

    def scrap(self, soup):
        target_data = self._target_data(soup)
        if target_data:
            splice_data = self._slice_data(target_data)
            list_data = self._split_string(splice_data)
            return self._convert_to_dictionary(list_data)
        return {str(year): None for year in range(2005, 2019)}
        