import time
import busio
import adafruit_ads1x15.ads1115 as ADS
from adafruit_ads1x15.analog_in import AnalogIn

ads = ADS.ADS1115(i2c)

ads.gain = 1
chan = AnalogIn(ads, ADS.P0)
while True:
	print(f"Voltage: {chan.voltage:.2f} V")
	time.sleep(1)