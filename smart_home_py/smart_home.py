from air_conditioner import AirConditioner
from central_unit import CentralUnit
from data_provider import DataProvider
from switch import Switch
from water_heater import WaterHeater
import config

centralunit = CentralUnit(DataProvider(config.CITY, config.API_KEY))

centralunit.add_device(Switch())
centralunit.add_device(AirConditioner())
centralunit.add_device(WaterHeater(int(config.HOUR_OF_COMING_BACK_HOME), 
                                    int(config.MINUTE_OF_COMING_BACK_HOME)))

centralunit.run()
