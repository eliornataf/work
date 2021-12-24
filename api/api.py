from requests import get
from threading import Thread
from urllib.request import urlopen
from bs4 import BeautifulSoup
from math import ceil
import pandas as pd

WAYBACK_URL = "https://web.archive.org/cdx/search/cdx?"
CRAIGLIST_URL = "https://chicago.craigslist.org/d/musical-instruments/search/msa"

def fetch_data_from_wayback_api():
    response = get(WAYBACK_URL,
        headers={"Accept": "application/json"},
        params={"url": CRAIGLIST_URL, 
                "output": "json", 
                "fl": "timestamp", 
                "collapse": "digest",
                "filter": "statuscode:200"
        }
    )

    if response.status_code == 200: # success
        return response.json()
    raise ValueError(f"Response from API was: {response.status_code}")

def solution_part_one(data):
    result = {"datetime": [], "url": []}

    for i in range(1, len(data)): # skip header 
        timestamp = data[i][0]
        result["datetime"].append(timestamp[:4] + "/" + timestamp[4:6] + "/" + timestamp[6:8] + " " + timestamp[8:10] + ":" + timestamp[10:12] + ":" + timestamp[12:14]) # datetime format yyyy/mm/dd hh:mm:ss 
        url = "https://web.archive.org/web/" + timestamp + "/" + CRAIGLIST_URL
        result["url"].append(url)

    return result

def thread_function(datetime, url, result):       
    content = urlopen(url).read()
    soup = BeautifulSoup(content, "html.parser")
    text = soup.find(class_="totalcount").get_text() # url results total count
    number_of_pages = ceil(int(text) / 120) # 120 results per page

    result["datetime"].append(datetime)
    result["#pages"].append(number_of_pages)
    result["url"].append(url)

def solution_part_two(soultion):
    result = {"datetime": [], "#pages": [], "url": []}
    threads = []

    for i in range(len(soultion["datetime"])):
        new_thread = Thread(target=thread_function, args=(soultion["datetime"][i], soultion["url"][i], result))
        threads.append(new_thread)
        new_thread.start()
    
    [thread.join() for thread in threads]

    return result

def main():
    data = fetch_data_from_wayback_api()

    solution_dictionary_part_one = solution_part_one(data)    
    pd.DataFrame(solution_dictionary_part_one).to_csv("solution_part_one.csv", index=False)

    solution_dictionary_part_two = solution_part_two(solution_dictionary_part_one)
    pd.DataFrame(solution_dictionary_part_two).sort_values(by="datetime").to_csv("solution_part_two.csv", index=False)

if __name__ == '__main__':
    main()