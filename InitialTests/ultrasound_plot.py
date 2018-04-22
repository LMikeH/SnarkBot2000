#!/usr/bin/python
# -*- coding: utf-8 -*-

from pyqtgraph.Qt import QtGui, QtCore
import numpy as np
import pyqtgraph as pg
from pyqtgraph.ptime import time
import serial

app = QtGui.QApplication([])

p = pg.plot()
p.setWindowTitle('live plot from serial')
p.setYRange(0,100)
curve = p.plot()

data = [0]
raw=serial.Serial("/dev/ttyACM0",9600)
#raw.open()

def update():
    global curve, data
    line = raw.readline()
    data.append(float(line))
    if len(data) > 50:
        data.pop(0)
    xdata = np.array(data, dtype='float64')
    curve.setData(xdata)
    app.processEvents()

timer = QtCore.QTimer()
timer.timeout.connect(update)
timer.start(0)

if __name__ == '__main__':
    import sys
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
        QtGui.QApplication.instance().exec_()