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

## @package ProgressInfoPresentor
# @ingroup bin.controller
# @brief Abstract class for handling events from Learner and Solver
# @version $CURR$

from bin.controller.LearnerEventController import LearnerEventController


class ProgressInfoPresentor(LearnerEventController):
    """ generated source for ProgressInfoPresentor

    """
    verbose = None
    outputStream = None

    def handleSolvingEvent(self, subject, status):
        raise NotImplementedError

    def handleLearningEvent(self, subject, status):
        raise NotImplementedError


