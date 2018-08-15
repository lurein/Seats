import serial
import requests
arduinoData = serial.Serial('/dev/cu.usbmodem1421', 9600)
aduinoNew1 = {}
aduinoNew1['status'] = ''
while True:
    #print aduinoNew1
    aduinoNew = {}
    arduinoInfo = arduinoData.readline()
    dataSet = arduinoInfo.split(';')
    aduinoID = dataSet[0]
    aduinoStatus = dataSet[1]
    aduinoTable = '1'
    aduinoPerson = ['Jessica', 'John', 'Leahy']
    aduinoNew['members'] = aduinoPerson
    aduinoNew['table'] = aduinoTable
    aduinoNew['seatID'] = aduinoID
    aduinoNew['status'] = aduinoStatus
    if (aduinoNew['status'] != aduinoNew1['status']):
        r = requests.post(
            'http://www.diningspots.co.nf/api/newListing.php', data=aduinoNew)
        aduinoNew1 = aduinoNew
