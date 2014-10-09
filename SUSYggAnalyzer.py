#!/usr/bin/env python



import sys, os, time, StringIO, pickle
from commands import getoutput,getstatusoutput
from random import *

from ROOT import *


def hit_continue(msg='Hit any key to continue'):
	print msg
	sys.stdout.flush()
	raw_input('')




if len(sys.argv)<2:
	runDat="latest.root"
else: runDat=sys.argv[1]

print "Processing file:", runDat


#gROOT.ProcessLine(".L EventTree.C")

gROOT.ProcessLine(".L SUSYggAnalyzer.C+")

SUSYggAnalyzer(runDat)

hit_continue('Hit any key to exit')









