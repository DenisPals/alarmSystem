from datetime import datetime
import time
import serial
from pushbullet import PushBullet


ser = serial.Serial('COM4', 9800, timeout=1)
time.sleep(2)

token = 'o.GqRdw92oZIe7VLmWhATN7D3UEtP6Cus7'
pb = PushBullet(token)

counter = 0
while True:
    line = ser.readline()
    now = datetime.now().strftime("%H:%M")
    if line:
        try:
            string = line.decode()
            if string.strip() == 'ALARM':
                pb.push_note(f'ALARM {now}', 'MOTION SENSOR ALARM TRIGGERED! Contact Police and inform the neighboors!')
                counter += 1
        except ValueError:
            pb.push_note(f'CAUTION {now}', 'MOTION SENSOR ALARM MIGHT HAVE TRIGGERED! ValueError on SerialPort, inspect alarm device!')
    if counter >= 5:
        pb.push_note(f'ALARM {now}', 'Last notification: MOTION SENSOR ALARM TRIGGERED! Contact Police and inform the neighboors!')
        break

ser.close()
