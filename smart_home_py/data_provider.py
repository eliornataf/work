from data_provider_error import DataProviderError
from requests import get

class DataProvider():
    """Class to collect weather information for a given city from openweathermap.org"""

    def __init__(self, city, apikey):
        if not isinstance(city, str) or not city:
            raise DataProviderError(f"city must be non-empty string")
        if not isinstance(apikey, str) or not apikey:
            raise DataProviderError(f"apikey must be non-empty string")
            
        self._base_url = "http://api.openweathermap.org/data/2.5/weather?"
        self._city = city
        self._apikey = apikey
        self._units = "metric" # Celsius value

    @property
    def city(self):
        return self._city

    @property
    def _api_response(self):
        return get(
            self._base_url,
	        headers={"Accept": "application/json"},
            params={"q": self._city, "appid": self._apikey, "units": self._units}
        )

    def fetch_data(self):
        if self._api_response.status_code == 200: # Success
            return self._api_response.json()["main"]["temp"]
        else:
            raise DataProviderError(f"Response from API was: {self._api_response.status_code}")

