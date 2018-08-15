# This script read data from the Arduino and pushed it to our api server
import serial
import requests
arduinoData = serial.Serial('/dev/cu.usbmodem1421', 9600)
arduinoNew1 = {}
arduinoNew1['status'] = ''
while True:
    #print arduinoNew1
    arduinoNew = {}
    arduinoInfo = arduinoData.readline()
    dataSet = arduinoInfo.split(';')
    arduinoID = dataSet[0]
    arduinoStatus = dataSet[1]
    arduinoTable = '1'
    arduinoPerson = ['Jessica', 'John', 'Leahy']
    arduinoNew['members'] = arduinoPerson
    arduinoNew['table'] = arduinoTable
    arduinoNew['seatID'] = arduinoID
    arduinoNew['status'] = arduinoStatus
    if (arduinoNew['status'] != arduinoNew1['status']):
        r = requests.post(
            'http://www.diningspots.co.nf/api/newListing.php', data=arduinoNew)
        arduinoNew1 = arduinoNew
