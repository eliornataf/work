import pandas as pd

class Serializer():
    """This class converts a solution into a CSV file using the pandas statistical library"""

    def __init__(self, part_one_data_soultion, part_two_data_soultion):
        self._part_one_data_soultion = part_one_data_soultion
        self._part_two_data_soultion = part_two_data_soultion

    def _convert_part_one_soultion_into_a_csv_file(self):
        df = pd.DataFrame(self._part_one_data_soultion)[["Zip Code", "Current Population", "2005", "2006", "2007", "2008", "2009", "2010", "2011", "2012", "2013", "2014", "2015", "2016", "2017", "2018"]]
        df = df.sort_values(by="Zip Code")
        df.to_csv("solution_part_one.csv", index=False)

    def _convert_part_two_soultion_into_a_csv_file(self):
        df = pd.DataFrame(self._part_two_data_soultion)[["Zip Code", "Current Population", "Male Population Value", "Male Population Parentage", "Female Population Value", "Female Population Parentage"]]
        df = df.sort_values(by="Zip Code")
        df.to_csv("solution_part_two.csv", index=False)

    def serialize(self):
        self._convert_part_one_soultion_into_a_csv_file()
        self._convert_part_two_soultion_into_a_csv_file()
