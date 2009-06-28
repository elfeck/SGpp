##############################################################################
# This file is part of pysgpp, a program package making use of spatially    #
# adaptive sparse grids to solve numerical problems                         #
#                                                                           #
# Copyright (C) 2009 Valeriy Khakhutskyy (khakhutv@in.tum.de)               #
#                                                                           #
# pysgpp is free software; you can redistribute it and/or modify            #
# it under the terms of the GNU General Public License as published by      #
# the Free Software Foundation; either version 3 of the License, or         #
# (at your option) any later version.                                       #
#                                                                           #
# pysgpp is distributed in the hope that it will be useful,                 #
# but WITHOUT ANY WARRANTY; without even the implied warranty of            #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             #
# GNU Lesser General Public License for more details.                       #
#                                                                           #
# You should have received a copy of the GNU General Public License         #
# along with pysgpp; if not, write to the Free Software                     #
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA #
# or see <http://www.gnu.org/licenses/>.                                    #
#############################################################################

## @package InfoToFile
# @ingroup bin.controller
# @brief Class for handling events from Learner and Solver and printing informations to the file
# @version $CURR$

from bin.controller.InfoToScreen import InfoToScreen
import sys

class InfoToFile(InfoToScreen):

    filename = None #Filename, where output should be written
    
    ##
    #Constructor
    #
    #@param filename: filename where output should be written as string 
    def __init__(self, filename):
        self.filename = filename
        
        
    ##
    #Handles events from Linear Solver 
    #
    #@param subject: Linear Solver object
    #@param status: Event Status of type LinearSolverEvents
    ##       
    def handleSolvingEvent(self, subject, status):
        file = open(self.filename, "a")
        tmpout = sys.stdout
        sys.stdout = file
        InfoToScreen.handleSolvingEvent(self, subject, status)
        sys.stdout = tmpout
        file.close()
        
        
    ##
    #Handles events from Learner 
    #
    #@param subject: Learner object
    #@param status: Event Status of type LearnerEvents
    ##        
    def handleLearningEvent(self, subject, status):
        file = open(self.filename, "a")
        tmpout = sys.stdout
        sys.stdout = file
        InfoToScreen.handleSolvingEvent(self, subject, status)
        sys.stdout = tmpout
        file.close()
