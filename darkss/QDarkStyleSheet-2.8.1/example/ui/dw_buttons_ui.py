# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'dw_buttons.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from qtpy import QtCore, QtGui, QtWidgets


class Ui_DockWidget(object):
    def setupUi(self, DockWidget):
        DockWidget.setObjectName("DockWidget")
        DockWidget.resize(652, 491)
        self.dockWidgetContents = QtWidgets.QWidget()
        self.dockWidgetContents.setObjectName("dockWidgetContents")
        self.gridLayout = QtWidgets.QGridLayout(self.dockWidgetContents)
        self.gridLayout.setObjectName("gridLayout")
        self.label_72 = QtWidgets.QLabel(self.dockWidgetContents)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_72.setFont(font)
        self.label_72.setObjectName("label_72")
        self.gridLayout.addWidget(self.label_72, 0, 1, 1, 1)
        self.label_73 = QtWidgets.QLabel(self.dockWidgetContents)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_73.setFont(font)
        self.label_73.setObjectName("label_73")
        self.gridLayout.addWidget(self.label_73, 0, 3, 1, 1)
        self.label_26 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_26.setMinimumSize(QtCore.QSize(0, 0))
        self.label_26.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_26.setFont(font)
        self.label_26.setObjectName("label_26")
        self.gridLayout.addWidget(self.label_26, 1, 0, 1, 1)
        self.pushButton = QtWidgets.QPushButton(self.dockWidgetContents)
        self.pushButton.setMinimumSize(QtCore.QSize(0, 0))
        self.pushButton.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.pushButton.setObjectName("pushButton")
        self.gridLayout.addWidget(self.pushButton, 1, 1, 1, 1)
        self.pushButtonDis = QtWidgets.QPushButton(self.dockWidgetContents)
        self.pushButtonDis.setEnabled(False)
        self.pushButtonDis.setMinimumSize(QtCore.QSize(0, 0))
        self.pushButtonDis.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.pushButtonDis.setDefault(False)
        self.pushButtonDis.setObjectName("pushButtonDis")
        self.gridLayout.addWidget(self.pushButtonDis, 1, 3, 1, 1)
        self.label_74 = QtWidgets.QLabel(self.dockWidgetContents)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_74.setFont(font)
        self.label_74.setObjectName("label_74")
        self.gridLayout.addWidget(self.label_74, 2, 0, 1, 1)
        self.pushButtonChecked = QtWidgets.QPushButton(self.dockWidgetContents)
        self.pushButtonChecked.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.pushButtonChecked.setCheckable(True)
        self.pushButtonChecked.setChecked(True)
        self.pushButtonChecked.setObjectName("pushButtonChecked")
        self.gridLayout.addWidget(self.pushButtonChecked, 2, 1, 1, 1)
        self.pushButtonCheckedDis = QtWidgets.QPushButton(self.dockWidgetContents)
        self.pushButtonCheckedDis.setEnabled(False)
        self.pushButtonCheckedDis.setCheckable(True)
        self.pushButtonCheckedDis.setChecked(True)
        self.pushButtonCheckedDis.setObjectName("pushButtonCheckedDis")
        self.gridLayout.addWidget(self.pushButtonCheckedDis, 2, 3, 1, 1)
        self.label_76 = QtWidgets.QLabel(self.dockWidgetContents)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_76.setFont(font)
        self.label_76.setObjectName("label_76")
        self.gridLayout.addWidget(self.label_76, 3, 0, 1, 1)
        self.pushButtonUnchecked = QtWidgets.QPushButton(self.dockWidgetContents)
        self.pushButtonUnchecked.setCheckable(True)
        self.pushButtonUnchecked.setObjectName("pushButtonUnchecked")
        self.gridLayout.addWidget(self.pushButtonUnchecked, 3, 1, 1, 1)
        self.pushButtonUncheckedDis = QtWidgets.QPushButton(self.dockWidgetContents)
        self.pushButtonUncheckedDis.setEnabled(False)
        self.pushButtonUncheckedDis.setCheckable(True)
        self.pushButtonUncheckedDis.setObjectName("pushButtonUncheckedDis")
        self.gridLayout.addWidget(self.pushButtonUncheckedDis, 3, 3, 1, 1)
        self.label_33 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_33.setMinimumSize(QtCore.QSize(0, 0))
        self.label_33.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_33.setFont(font)
        self.label_33.setObjectName("label_33")
        self.gridLayout.addWidget(self.label_33, 4, 0, 1, 1)
        self.toolButton = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButton.setMinimumSize(QtCore.QSize(0, 0))
        self.toolButton.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.toolButton.setObjectName("toolButton")
        self.gridLayout.addWidget(self.toolButton, 4, 1, 1, 1)
        self.toolButtonIcon = QtWidgets.QToolButton(self.dockWidgetContents)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(":/qss_icons/rc/window_undock@2x.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.toolButtonIcon.setIcon(icon)
        self.toolButtonIcon.setObjectName("toolButtonIcon")
        self.gridLayout.addWidget(self.toolButtonIcon, 4, 2, 1, 1)
        self.toolButtonDis = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonDis.setEnabled(False)
        self.toolButtonDis.setMinimumSize(QtCore.QSize(0, 0))
        self.toolButtonDis.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.toolButtonDis.setObjectName("toolButtonDis")
        self.gridLayout.addWidget(self.toolButtonDis, 4, 3, 1, 1)
        self.toolButtonIconDis = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonIconDis.setEnabled(False)
        self.toolButtonIconDis.setObjectName("toolButtonIconDis")
        self.gridLayout.addWidget(self.toolButtonIconDis, 4, 4, 1, 1)
        self.label_2 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_2.setObjectName("label_2")
        self.gridLayout.addWidget(self.label_2, 5, 0, 1, 1)
        self.toolButtonChecked = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonChecked.setCheckable(True)
        self.toolButtonChecked.setChecked(True)
        self.toolButtonChecked.setPopupMode(QtWidgets.QToolButton.DelayedPopup)
        self.toolButtonChecked.setObjectName("toolButtonChecked")
        self.gridLayout.addWidget(self.toolButtonChecked, 5, 1, 1, 1)
        self.toolButtonCheckedIcon = QtWidgets.QToolButton(self.dockWidgetContents)
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(":/qss_icons/rc/window_undock.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.toolButtonCheckedIcon.setIcon(icon1)
        self.toolButtonCheckedIcon.setCheckable(True)
        self.toolButtonCheckedIcon.setChecked(True)
        self.toolButtonCheckedIcon.setObjectName("toolButtonCheckedIcon")
        self.gridLayout.addWidget(self.toolButtonCheckedIcon, 5, 2, 1, 1)
        self.toolButtonCheckedDis = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonCheckedDis.setEnabled(False)
        self.toolButtonCheckedDis.setCheckable(True)
        self.toolButtonCheckedDis.setChecked(True)
        self.toolButtonCheckedDis.setPopupMode(QtWidgets.QToolButton.DelayedPopup)
        self.toolButtonCheckedDis.setObjectName("toolButtonCheckedDis")
        self.gridLayout.addWidget(self.toolButtonCheckedDis, 5, 3, 1, 1)
        self.toolButtonCheckedIconDis = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonCheckedIconDis.setEnabled(False)
        self.toolButtonCheckedIconDis.setCheckable(True)
        self.toolButtonCheckedIconDis.setChecked(True)
        self.toolButtonCheckedIconDis.setObjectName("toolButtonCheckedIconDis")
        self.gridLayout.addWidget(self.toolButtonCheckedIconDis, 5, 4, 1, 1)
        self.label_3 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_3.setObjectName("label_3")
        self.gridLayout.addWidget(self.label_3, 6, 0, 1, 1)
        self.gridLayout_3 = QtWidgets.QGridLayout()
        self.gridLayout_3.setObjectName("gridLayout_3")
        self.toolButtonArrowUp = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonArrowUp.setArrowType(QtCore.Qt.UpArrow)
        self.toolButtonArrowUp.setObjectName("toolButtonArrowUp")
        self.gridLayout_3.addWidget(self.toolButtonArrowUp, 0, 1, 1, 1)
        self.toolButtonArrowLeft = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonArrowLeft.setArrowType(QtCore.Qt.LeftArrow)
        self.toolButtonArrowLeft.setObjectName("toolButtonArrowLeft")
        self.gridLayout_3.addWidget(self.toolButtonArrowLeft, 0, 3, 1, 1)
        self.toolButtonArrowRight = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonArrowRight.setArrowType(QtCore.Qt.RightArrow)
        self.toolButtonArrowRight.setObjectName("toolButtonArrowRight")
        self.gridLayout_3.addWidget(self.toolButtonArrowRight, 0, 2, 1, 1)
        self.toolButtonArrowDown = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonArrowDown.setArrowType(QtCore.Qt.DownArrow)
        self.toolButtonArrowDown.setObjectName("toolButtonArrowDown")
        self.gridLayout_3.addWidget(self.toolButtonArrowDown, 0, 0, 1, 1)
        self.toolButtonDots = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonDots.setObjectName("toolButtonDots")
        self.gridLayout_3.addWidget(self.toolButtonDots, 0, 4, 1, 1)
        self.gridLayout.addLayout(self.gridLayout_3, 6, 1, 1, 2)
        self.gridLayout_2 = QtWidgets.QGridLayout()
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.toolButtonArrowUpDis = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonArrowUpDis.setEnabled(False)
        self.toolButtonArrowUpDis.setArrowType(QtCore.Qt.UpArrow)
        self.toolButtonArrowUpDis.setObjectName("toolButtonArrowUpDis")
        self.gridLayout_2.addWidget(self.toolButtonArrowUpDis, 0, 1, 1, 1)
        self.toolButtonArrowDownDis = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonArrowDownDis.setEnabled(False)
        self.toolButtonArrowDownDis.setArrowType(QtCore.Qt.DownArrow)
        self.toolButtonArrowDownDis.setObjectName("toolButtonArrowDownDis")
        self.gridLayout_2.addWidget(self.toolButtonArrowDownDis, 0, 0, 1, 1)
        self.toolButtonArrowRightDis = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonArrowRightDis.setEnabled(False)
        self.toolButtonArrowRightDis.setArrowType(QtCore.Qt.RightArrow)
        self.toolButtonArrowRightDis.setObjectName("toolButtonArrowRightDis")
        self.gridLayout_2.addWidget(self.toolButtonArrowRightDis, 0, 2, 1, 1)
        self.toolButtonArrowLeftDis = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonArrowLeftDis.setEnabled(False)
        self.toolButtonArrowLeftDis.setArrowType(QtCore.Qt.LeftArrow)
        self.toolButtonArrowLeftDis.setObjectName("toolButtonArrowLeftDis")
        self.gridLayout_2.addWidget(self.toolButtonArrowLeftDis, 0, 3, 1, 1)
        self.toolButtonDotsDis = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonDotsDis.setEnabled(False)
        self.toolButtonDotsDis.setObjectName("toolButtonDotsDis")
        self.gridLayout_2.addWidget(self.toolButtonDotsDis, 0, 4, 1, 1)
        self.gridLayout.addLayout(self.gridLayout_2, 6, 3, 1, 2)
        self.label_4 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_4.setObjectName("label_4")
        self.gridLayout.addWidget(self.label_4, 7, 0, 1, 1)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.toolButtonDelayedPopup = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonDelayedPopup.setArrowType(QtCore.Qt.NoArrow)
        self.toolButtonDelayedPopup.setObjectName("toolButtonDelayedPopup")
        self.horizontalLayout.addWidget(self.toolButtonDelayedPopup)
        self.toolButtonMenuButtonPopup = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonMenuButtonPopup.setPopupMode(QtWidgets.QToolButton.MenuButtonPopup)
        self.toolButtonMenuButtonPopup.setObjectName("toolButtonMenuButtonPopup")
        self.horizontalLayout.addWidget(self.toolButtonMenuButtonPopup)
        self.toolButtonInstantPopup = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonInstantPopup.setPopupMode(QtWidgets.QToolButton.InstantPopup)
        self.toolButtonInstantPopup.setObjectName("toolButtonInstantPopup")
        self.horizontalLayout.addWidget(self.toolButtonInstantPopup)
        self.gridLayout.addLayout(self.horizontalLayout, 7, 1, 1, 2)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.toolButtonDelayedPopupDis = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonDelayedPopupDis.setEnabled(False)
        self.toolButtonDelayedPopupDis.setArrowType(QtCore.Qt.NoArrow)
        self.toolButtonDelayedPopupDis.setObjectName("toolButtonDelayedPopupDis")
        self.horizontalLayout_2.addWidget(self.toolButtonDelayedPopupDis)
        self.toolButtonMenuButtonPopupDis = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonMenuButtonPopupDis.setEnabled(False)
        self.toolButtonMenuButtonPopupDis.setPopupMode(QtWidgets.QToolButton.MenuButtonPopup)
        self.toolButtonMenuButtonPopupDis.setObjectName("toolButtonMenuButtonPopupDis")
        self.horizontalLayout_2.addWidget(self.toolButtonMenuButtonPopupDis)
        self.toolButtonInstantPopupDis = QtWidgets.QToolButton(self.dockWidgetContents)
        self.toolButtonInstantPopupDis.setEnabled(False)
        self.toolButtonInstantPopupDis.setPopupMode(QtWidgets.QToolButton.InstantPopup)
        self.toolButtonInstantPopupDis.setObjectName("toolButtonInstantPopupDis")
        self.horizontalLayout_2.addWidget(self.toolButtonInstantPopupDis)
        self.gridLayout.addLayout(self.horizontalLayout_2, 7, 3, 1, 2)
        self.label_75 = QtWidgets.QLabel(self.dockWidgetContents)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_75.setFont(font)
        self.label_75.setObjectName("label_75")
        self.gridLayout.addWidget(self.label_75, 8, 0, 1, 1)
        self.radioButtonChecked = QtWidgets.QRadioButton(self.dockWidgetContents)
        self.radioButtonChecked.setChecked(True)
        self.radioButtonChecked.setAutoExclusive(False)
        self.radioButtonChecked.setObjectName("radioButtonChecked")
        self.gridLayout.addWidget(self.radioButtonChecked, 8, 1, 1, 1)
        self.radioButtonCheckedDis = QtWidgets.QRadioButton(self.dockWidgetContents)
        self.radioButtonCheckedDis.setEnabled(False)
        self.radioButtonCheckedDis.setChecked(True)
        self.radioButtonCheckedDis.setAutoExclusive(False)
        self.radioButtonCheckedDis.setObjectName("radioButtonCheckedDis")
        self.gridLayout.addWidget(self.radioButtonCheckedDis, 8, 3, 1, 1)
        self.label_29 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_29.setMinimumSize(QtCore.QSize(0, 0))
        self.label_29.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_29.setFont(font)
        self.label_29.setObjectName("label_29")
        self.gridLayout.addWidget(self.label_29, 9, 0, 1, 1)
        self.radioButtonUnchecked = QtWidgets.QRadioButton(self.dockWidgetContents)
        self.radioButtonUnchecked.setMinimumSize(QtCore.QSize(0, 0))
        self.radioButtonUnchecked.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.radioButtonUnchecked.setAutoExclusive(False)
        self.radioButtonUnchecked.setObjectName("radioButtonUnchecked")
        self.gridLayout.addWidget(self.radioButtonUnchecked, 9, 1, 1, 1)
        self.radioButtonUncheckedDis = QtWidgets.QRadioButton(self.dockWidgetContents)
        self.radioButtonUncheckedDis.setEnabled(False)
        self.radioButtonUncheckedDis.setMinimumSize(QtCore.QSize(0, 0))
        self.radioButtonUncheckedDis.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.radioButtonUncheckedDis.setChecked(False)
        self.radioButtonUncheckedDis.setAutoExclusive(False)
        self.radioButtonUncheckedDis.setObjectName("radioButtonUncheckedDis")
        self.gridLayout.addWidget(self.radioButtonUncheckedDis, 9, 3, 1, 1)
        self.label_53 = QtWidgets.QLabel(self.dockWidgetContents)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_53.setFont(font)
        self.label_53.setObjectName("label_53")
        self.gridLayout.addWidget(self.label_53, 10, 0, 1, 1)
        self.checkBoxChecked = QtWidgets.QCheckBox(self.dockWidgetContents)
        self.checkBoxChecked.setChecked(True)
        self.checkBoxChecked.setObjectName("checkBoxChecked")
        self.gridLayout.addWidget(self.checkBoxChecked, 10, 1, 1, 1)
        self.checkBoxCheckedDis = QtWidgets.QCheckBox(self.dockWidgetContents)
        self.checkBoxCheckedDis.setEnabled(False)
        self.checkBoxCheckedDis.setChecked(True)
        self.checkBoxCheckedDis.setObjectName("checkBoxCheckedDis")
        self.gridLayout.addWidget(self.checkBoxCheckedDis, 10, 3, 1, 1)
        self.label_30 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_30.setMinimumSize(QtCore.QSize(0, 0))
        self.label_30.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_30.setFont(font)
        self.label_30.setObjectName("label_30")
        self.gridLayout.addWidget(self.label_30, 11, 0, 1, 1)
        self.checkBoxEnabled = QtWidgets.QCheckBox(self.dockWidgetContents)
        self.checkBoxEnabled.setMinimumSize(QtCore.QSize(0, 0))
        self.checkBoxEnabled.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.checkBoxEnabled.setTristate(False)
        self.checkBoxEnabled.setObjectName("checkBoxEnabled")
        self.gridLayout.addWidget(self.checkBoxEnabled, 11, 1, 1, 1)
        self.checkBoxUncheckedDis = QtWidgets.QCheckBox(self.dockWidgetContents)
        self.checkBoxUncheckedDis.setEnabled(False)
        self.checkBoxUncheckedDis.setMinimumSize(QtCore.QSize(0, 0))
        self.checkBoxUncheckedDis.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.checkBoxUncheckedDis.setChecked(False)
        self.checkBoxUncheckedDis.setObjectName("checkBoxUncheckedDis")
        self.gridLayout.addWidget(self.checkBoxUncheckedDis, 11, 3, 1, 1)
        self.label = QtWidgets.QLabel(self.dockWidgetContents)
        self.label.setObjectName("label")
        self.gridLayout.addWidget(self.label, 12, 0, 1, 1)
        self.checkBoxTristate = QtWidgets.QCheckBox(self.dockWidgetContents)
        self.checkBoxTristate.setChecked(False)
        self.checkBoxTristate.setTristate(True)
        self.checkBoxTristate.setObjectName("checkBoxTristate")
        self.gridLayout.addWidget(self.checkBoxTristate, 12, 1, 1, 1)
        self.checkBoxTristateDis = QtWidgets.QCheckBox(self.dockWidgetContents)
        self.checkBoxTristateDis.setEnabled(False)
        self.checkBoxTristateDis.setChecked(False)
        self.checkBoxTristateDis.setTristate(True)
        self.checkBoxTristateDis.setObjectName("checkBoxTristateDis")
        self.gridLayout.addWidget(self.checkBoxTristateDis, 12, 3, 1, 1)
        self.label_31 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_31.setMinimumSize(QtCore.QSize(0, 0))
        self.label_31.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_31.setFont(font)
        self.label_31.setObjectName("label_31")
        self.gridLayout.addWidget(self.label_31, 13, 0, 1, 1)
        self.commandLinkButton = QtWidgets.QCommandLinkButton(self.dockWidgetContents)
        self.commandLinkButton.setMinimumSize(QtCore.QSize(0, 0))
        self.commandLinkButton.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.commandLinkButton.setObjectName("commandLinkButton")
        self.gridLayout.addWidget(self.commandLinkButton, 13, 1, 1, 2)
        self.commandLinkButtonDIs = QtWidgets.QCommandLinkButton(self.dockWidgetContents)
        self.commandLinkButtonDIs.setEnabled(False)
        self.commandLinkButtonDIs.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.commandLinkButtonDIs.setObjectName("commandLinkButtonDIs")
        self.gridLayout.addWidget(self.commandLinkButtonDIs, 13, 3, 1, 2)
        self.label_32 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_32.setMinimumSize(QtCore.QSize(0, 0))
        self.label_32.setMaximumSize(QtCore.QSize(16777215, 16777215))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_32.setFont(font)
        self.label_32.setObjectName("label_32")
        self.gridLayout.addWidget(self.label_32, 14, 0, 1, 1)
        self.buttonBox = QtWidgets.QDialogButtonBox(self.dockWidgetContents)
        self.buttonBox.setMinimumSize(QtCore.QSize(0, 0))
        self.buttonBox.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.buttonBox.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.gridLayout.addWidget(self.buttonBox, 14, 1, 1, 2)
        self.buttonBoxDis = QtWidgets.QDialogButtonBox(self.dockWidgetContents)
        self.buttonBoxDis.setEnabled(False)
        self.buttonBoxDis.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBoxDis.setObjectName("buttonBoxDis")
        self.gridLayout.addWidget(self.buttonBoxDis, 14, 3, 1, 2)
        spacerItem = QtWidgets.QSpacerItem(20, 4, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout.addItem(spacerItem, 15, 0, 1, 1)
        self.label_36 = QtWidgets.QLabel(self.dockWidgetContents)
        self.label_36.setAlignment(QtCore.Qt.AlignCenter)
        self.label_36.setObjectName("label_36")
        self.gridLayout.addWidget(self.label_36, 16, 0, 1, 5)
        DockWidget.setWidget(self.dockWidgetContents)

        self.retranslateUi(DockWidget)
        self.radioButtonChecked.clicked['bool'].connect(self.radioButtonCheckedDis.setChecked)
        self.radioButtonUnchecked.clicked['bool'].connect(self.radioButtonUncheckedDis.setChecked)
        self.checkBoxChecked.clicked['bool'].connect(self.checkBoxCheckedDis.setChecked)
        self.checkBoxEnabled.clicked['bool'].connect(self.checkBoxUncheckedDis.setChecked)
        self.checkBoxTristate.clicked['bool'].connect(self.checkBoxTristateDis.setChecked)
        self.commandLinkButton.clicked['bool'].connect(self.commandLinkButtonDIs.setChecked)
        self.toolButton.clicked['bool'].connect(self.toolButtonDis.setChecked)
        self.pushButtonChecked.clicked['bool'].connect(self.pushButtonCheckedDis.setChecked)
        self.pushButtonUnchecked.clicked['bool'].connect(self.pushButtonUncheckedDis.setChecked)
        self.pushButton.clicked['bool'].connect(self.pushButtonDis.click)
        QtCore.QMetaObject.connectSlotsByName(DockWidget)

    def retranslateUi(self, DockWidget):
        _translate = QtCore.QCoreApplication.translate
        DockWidget.setWindowTitle(_translate("DockWidget", "Buttons"))
        self.label_72.setText(_translate("DockWidget", "Enabled"))
        self.label_73.setText(_translate("DockWidget", "Disabled"))
        self.label_26.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_26.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_26.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_26.setText(_translate("DockWidget", "PushButton"))
        self.pushButton.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.pushButton.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.pushButton.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.pushButton.setText(_translate("DockWidget", "OK"))
        self.pushButtonDis.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.pushButtonDis.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.pushButtonDis.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.pushButtonDis.setText(_translate("DockWidget", "OK"))
        self.label_74.setText(_translate("DockWidget", "PushButton"))
        self.pushButtonChecked.setText(_translate("DockWidget", "Checked"))
        self.pushButtonCheckedDis.setText(_translate("DockWidget", "Checked"))
        self.label_76.setText(_translate("DockWidget", "PushButton"))
        self.pushButtonUnchecked.setText(_translate("DockWidget", "Unchecked"))
        self.pushButtonUncheckedDis.setText(_translate("DockWidget", "Unchecked"))
        self.label_33.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_33.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_33.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_33.setText(_translate("DockWidget", "ToolButton"))
        self.toolButton.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.toolButton.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.toolButton.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.toolButton.setText(_translate("DockWidget", "Tool"))
        self.toolButtonIcon.setText(_translate("DockWidget", "Icon"))
        self.toolButtonDis.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.toolButtonDis.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.toolButtonDis.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.toolButtonDis.setText(_translate("DockWidget", "Tool"))
        self.toolButtonIconDis.setText(_translate("DockWidget", "Icon"))
        self.label_2.setText(_translate("DockWidget", "<html><head/><body><p><span style=\" font-weight:600;\">ToolButton</span></p></body></html>"))
        self.toolButtonChecked.setText(_translate("DockWidget", "Tool Checked"))
        self.toolButtonCheckedIcon.setText(_translate("DockWidget", "Icon Checked"))
        self.toolButtonCheckedDis.setText(_translate("DockWidget", "Tool Checked"))
        self.toolButtonCheckedIconDis.setText(_translate("DockWidget", "Icon Checked"))
        self.label_3.setText(_translate("DockWidget", "<html><head/><body><p><span style=\" font-weight:600;\">ToolButton</span></p></body></html>"))
        self.toolButtonArrowUp.setText(_translate("DockWidget", "..."))
        self.toolButtonArrowLeft.setText(_translate("DockWidget", "..."))
        self.toolButtonArrowRight.setText(_translate("DockWidget", "..."))
        self.toolButtonArrowDown.setText(_translate("DockWidget", "..."))
        self.toolButtonDots.setText(_translate("DockWidget", "..."))
        self.toolButtonArrowUpDis.setText(_translate("DockWidget", "..."))
        self.toolButtonArrowDownDis.setText(_translate("DockWidget", "..."))
        self.toolButtonArrowRightDis.setText(_translate("DockWidget", "..."))
        self.toolButtonArrowLeftDis.setText(_translate("DockWidget", "..."))
        self.toolButtonDotsDis.setText(_translate("DockWidget", "..."))
        self.label_4.setText(_translate("DockWidget", "<html><head/><body><p><span style=\" font-weight:600;\">ToolButton</span></p></body></html>"))
        self.toolButtonDelayedPopup.setText(_translate("DockWidget", "Delayed"))
        self.toolButtonMenuButtonPopup.setText(_translate("DockWidget", "Menu"))
        self.toolButtonInstantPopup.setText(_translate("DockWidget", "Instant"))
        self.toolButtonDelayedPopupDis.setText(_translate("DockWidget", "Delayed"))
        self.toolButtonMenuButtonPopupDis.setText(_translate("DockWidget", "Menu"))
        self.toolButtonInstantPopupDis.setText(_translate("DockWidget", "Instant"))
        self.label_75.setText(_translate("DockWidget", "RadioButton"))
        self.radioButtonChecked.setText(_translate("DockWidget", "Checked"))
        self.radioButtonCheckedDis.setText(_translate("DockWidget", "Checked"))
        self.label_29.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_29.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_29.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_29.setText(_translate("DockWidget", "RadioButton"))
        self.radioButtonUnchecked.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.radioButtonUnchecked.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.radioButtonUnchecked.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.radioButtonUnchecked.setText(_translate("DockWidget", "Unchecked"))
        self.radioButtonUncheckedDis.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.radioButtonUncheckedDis.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.radioButtonUncheckedDis.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.radioButtonUncheckedDis.setText(_translate("DockWidget", "Unchecked"))
        self.label_53.setText(_translate("DockWidget", "CheckBox"))
        self.checkBoxChecked.setText(_translate("DockWidget", "Checked"))
        self.checkBoxCheckedDis.setText(_translate("DockWidget", "Checked"))
        self.label_30.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_30.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_30.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_30.setText(_translate("DockWidget", "CheckBox"))
        self.checkBoxEnabled.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.checkBoxEnabled.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.checkBoxEnabled.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.checkBoxEnabled.setText(_translate("DockWidget", "Unchecked"))
        self.checkBoxUncheckedDis.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.checkBoxUncheckedDis.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.checkBoxUncheckedDis.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.checkBoxUncheckedDis.setText(_translate("DockWidget", "Unchecked"))
        self.label.setText(_translate("DockWidget", "CheckBox"))
        self.checkBoxTristate.setText(_translate("DockWidget", "Tristate"))
        self.checkBoxTristateDis.setText(_translate("DockWidget", "Tristate"))
        self.label_31.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_31.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_31.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_31.setText(_translate("DockWidget", "CommandLinkButton"))
        self.commandLinkButton.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.commandLinkButton.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.commandLinkButton.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.commandLinkButton.setText(_translate("DockWidget", "Command"))
        self.commandLinkButtonDIs.setText(_translate("DockWidget", "Command"))
        self.label_32.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_32.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_32.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_32.setText(_translate("DockWidget", "ButtonBox"))
        self.buttonBox.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.buttonBox.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.buttonBox.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_36.setToolTip(_translate("DockWidget", "This is a tool tip"))
        self.label_36.setStatusTip(_translate("DockWidget", "This is a status tip"))
        self.label_36.setWhatsThis(_translate("DockWidget", "This is \"what is this\""))
        self.label_36.setText(_translate("DockWidget", "Inside DockWidget"))
from qdarkstyle import style_rc
