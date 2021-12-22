from data_collection import DataCollection
from config import CSV_FILE_PATH, SCRAPERAPI_API_KEY

DataCollection(CSV_FILE_PATH, SCRAPERAPI_API_KEY).execute()