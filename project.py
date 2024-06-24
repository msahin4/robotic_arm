import cv2
import numpy as np
import serial

ser = serial.Serial('COM7', 9600)  

def arduino_veri_gonder(veri):
    veri += '\n'  
    ser.write(veri.encode('utf-8')) 

vid = cv2.VideoCapture(1)

while True:
    ret, frame = vid.read()

    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lower_black = np.array([0, 0, 0])
    upper_black = np.array([180, 255, 30])
    lower_orange = np.array([0, 100, 100])  
    upper_orange = np.array([20, 255, 255])

    black_mask = cv2.inRange(hsv_frame, lower_black, upper_black)
    orange_mask = cv2.inRange(hsv_frame, lower_orange, upper_orange)

    contours_black, _ = cv2.findContours(black_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contours_orange, _ = cv2.findContours(orange_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    if len(contours_black) > 0:
        largest_contour_black = max(contours_black, key=cv2.contourArea)
        rect_black = cv2.minAreaRect(largest_contour_black)
        box_black = cv2.boxPoints(rect_black)
        box_black = np.int0(box_black)
        cv2.drawContours(frame, [box_black], 0, (0, 255, 0), 2)
        x_black, y_black, _, _ = cv2.boundingRect(largest_contour_black)
        cv2.putText(frame, 'SIYAH', (x_black, y_black - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 255, 0), 2)
        
        arduino_veri_gonder('moveBlackBox') 

    elif len(contours_orange) > 0:
        largest_contour_orange = max(contours_orange, key=cv2.contourArea)
        rect_orange = cv2.minAreaRect(largest_contour_orange)
        box_orange = cv2.boxPoints(rect_orange)
        box_orange = np.int0(box_orange)
        cv2.drawContours(frame, [box_orange], 0, (0, 165, 255), 2)
        x_orange, y_orange, _, _ = cv2.boundingRect(largest_contour_orange)
        cv2.putText(frame, 'TURUNCU', (x_orange, y_orange - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 165, 255), 2)
        
        arduino_veri_gonder('moveOrangeBox')  

    cv2.imshow('frame', frame)
    cv2.imshow('black mask', black_mask)
    cv2.imshow('orange mask', orange_mask)

    kInp = cv2.waitKey(1)

    if kInp == ord('q'):
        break

vid.release()
cv2.destroyAllWindows()
