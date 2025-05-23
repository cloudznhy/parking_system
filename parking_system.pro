QT       += core gui sql
QT       += multimedia
QT       += multimediawidgets
QT       += charts
QT       +=network
QT       +=widgets
QT       +=charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# CONFIG += c++17
CONFIG += c++11
QMAKE_CXXFLAGS+=-std=c++11
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -Wno-unused-parameter

QMAKE_CXXFLAGS += -Wno-unused-variable

QMAKE_CXXFLAGS_WARN_ON -= -Wunused-function
QMAKE_CXXFLAGS += -Wno-unused-function


SOURCES += \
    car.cpp \
    initfile.cpp \
    main.cpp \
    mainwindow.cpp \
    mysql.cpp \
    mysqlinit.cpp \
    platerecognize.cpp \
    signup.cpp \
    updatepie.cpp

HEADERS += \
    car.h \
    initfile.h \
    mainwindow.h \
    mysql.h \
    mysqlinit.h \
    platerecognize.h \
    signup.h \
    updatepie.h

FORMS += \
    car.ui \
    initfile.ui \
    mainwindow.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resources/doc/res/13ver.jpg \
    resources/doc/res/arch.jpg \
    resources/doc/res/batch_operation.jpg \
    resources/doc/res/batch_result.png \
    resources/doc/res/big_1.jpg \
    resources/doc/res/bigangle.png \
    resources/doc/res/blue_chars.png \
    resources/doc/res/blue_plate.jpg \
    resources/doc/res/contrast_1.jpg \
    resources/doc/res/debug.jpg \
    resources/doc/res/extreme_test.jpg \
    resources/doc/res/fetures.png \
    resources/doc/res/gdsl.jpg \
    resources/doc/res/general_test.jpg \
    resources/doc/res/levenshtein1.jpg \
    resources/doc/res/levenshtein2.jpg \
    resources/doc/res/levenshtein3.jpg \
    resources/doc/res/levenshteinAll.JPG \
    resources/doc/res/lifemode.jpg \
    resources/doc/res/near_1.jpg \
    resources/doc/res/new50.jpg \
    resources/doc/res/night_1.jpg \
    resources/doc/res/night_2.jpg \
    resources/doc/res/normal_ostu.jpg \
    resources/doc/res/not_avg_contrast.jpg \
    resources/doc/res/one_image_detect.jpg \
    resources/doc/res/plate_detect.jpg \
    resources/doc/res/plate_locate.jpg \
    resources/doc/res/spatial_ostu.jpg \
    resources/doc/res/svm_data.jpg \
    resources/doc/res/svm_rate.jpg \
    resources/doc/res/svm_train.jpg \
    resources/doc/res/svm_upgragde.png \
    resources/doc/res/testresult.png \
    resources/doc/res/testresult_1.3alpha.png \
    resources/doc/res/testresult_1.3beta.png \
    resources/doc/res/v1.5_result.jpg \
    resources/doc/res/window.png \
    resources/doc/res/yellow_chars.png \
    resources/doc/res/yellow_plate.jpg \
    resources/doc/关于版权.txt \
    resources/image/GDSL.txt \
    resources/image/chars_identify.jpg \
    resources/image/chars_recognise.jpg \
    resources/image/chars_segment.jpg \
    resources/image/general_test/GroundTruth_others.xml \
    resources/image/general_test/GroundTruth_windows.xml \
    resources/image/general_test/京A88731.jpg \
    resources/image/general_test/京CX8888.jpg \
    resources/image/general_test/京FK5358.jpg \
    resources/image/general_test/京H99999.jpg \
    resources/image/general_test/京PC5U22.jpg \
    resources/image/general_test/冀FA3215.jpg \
    resources/image/general_test/川A019W2.jpg \
    resources/image/general_test/川A095Q5.jpg \
    resources/image/general_test/川A09X20.jpg \
    resources/image/general_test/川A105LR.jpg \
    resources/image/general_test/川A113YP.jpg \
    resources/image/general_test/川A561WP.jpg \
    resources/image/general_test/川A572F4.jpg \
    resources/image/general_test/川A762ZS.jpg \
    resources/image/general_test/川A82M83.jpg \
    resources/image/general_test/川A88888.jpg \
    resources/image/general_test/川AA662F.jpg \
    resources/image/general_test/川AE8H60.jpg \
    resources/image/general_test/川AEK882.jpg \
    resources/image/general_test/川AGU052.jpg \
    resources/image/general_test/川AGU801.jpg \
    resources/image/general_test/川AKM065.jpg \
    resources/image/general_test/川AKQ291.jpg \
    resources/image/general_test/川AL0Q87.jpg \
    resources/image/general_test/川AM1186.jpg \
    resources/image/general_test/川AN4E10.jpg \
    resources/image/general_test/川AR9X49.jpg \
    resources/image/general_test/川AS9V79.jpg \
    resources/image/general_test/川AUU093.jpg \
    resources/image/general_test/川AY116F.jpg \
    resources/image/general_test/川AZ408T.jpg \
    resources/image/general_test/川C28888.jpg \
    resources/image/general_test/川R35779.jpg \
    resources/image/general_test/桂ATK071.jpg \
    resources/image/general_test/沪A51V39.jpg \
    resources/image/general_test/沪AGH092.jpg \
    resources/image/general_test/沪ALB022.jpg \
    resources/image/general_test/沪AP0910.jpg \
    resources/image/general_test/沪B683J8.jpg \
    resources/image/general_test/沪D71603.jpg \
    resources/image/general_test/沪J32500.jpg \
    resources/image/general_test/沪JS6999.jpg \
    resources/image/general_test/沪K62933.jpg \
    resources/image/general_test/沪KT5583.jpg \
    resources/image/general_test/津AHP676.jpg \
    resources/image/general_test/津DTG667.jpg \
    resources/image/general_test/津E14579.jpg \
    resources/image/general_test/津E22602.jpg \
    resources/image/general_test/津E24494.jpg \
    resources/image/general_test/津E28437.jpg \
    resources/image/general_test/津G68991.jpg \
    resources/image/general_test/津H65817.jpg \
    resources/image/general_test/津JZ3999.jpg \
    resources/image/general_test/津KNG518.jpg \
    resources/image/general_test/津LS2999.jpg \
    resources/image/general_test/津MJY929.jpg \
    resources/image/general_test/津MN0888.jpg \
    resources/image/general_test/津NRL118.jpg \
    resources/image/general_test/津RB7992.jpg \
    resources/image/general_test/浙A03168.jpg \
    resources/image/general_test/浙A12210.jpg \
    resources/image/general_test/浙A12903.jpg \
    resources/image/general_test/浙A13840.jpg \
    resources/image/general_test/浙A21027.jpg \
    resources/image/general_test/浙A26M71.jpg \
    resources/image/general_test/浙A50819.jpg \
    resources/image/general_test/浙A54614.jpg \
    resources/image/general_test/浙A68952.jpg \
    resources/image/general_test/浙A72220.jpg \
    resources/image/general_test/浙A88888.jpg \
    resources/image/general_test/浙A95044.jpg \
    resources/image/general_test/浙AA2270.jpg \
    resources/image/general_test/浙AA4586.jpg \
    resources/image/general_test/浙AA5547.jpg \
    resources/image/general_test/浙AC1847.jpg \
    resources/image/general_test/浙AM690M.jpg \
    resources/image/general_test/浙B7C289.jpg \
    resources/image/general_test/浙C01701.jpg \
    resources/image/general_test/浙E6686V.jpg \
    resources/image/general_test/浙F397C0.jpg \
    resources/image/general_test/浙F99999.jpg \
    resources/image/general_test/浙G70000.jpg \
    resources/image/general_test/浙GZB388.jpg \
    resources/image/general_test/浙GZJ021.jpg \
    resources/image/general_test/浙JP291Q.jpg \
    resources/image/general_test/浙L11921.jpg \
    resources/image/general_test/浙L66736.jpg \
    resources/image/general_test/浙LD1930.jpg \
    resources/image/general_test/渝B3587学.jpg \
    resources/image/general_test/渝B777C9.jpg \
    resources/image/general_test/渝BE7773.jpg \
    resources/image/general_test/湘A05H22.jpg \
    resources/image/general_test/湘A07G31.jpg \
    resources/image/general_test/湘A0PC37.jpg \
    resources/image/general_test/湘A0PQ76.jpg \
    resources/image/general_test/湘A2991D.jpg \
    resources/image/general_test/湘A31Y83.jpg \
    resources/image/general_test/湘A3685C.jpg \
    resources/image/general_test/湘A3MA06.jpg \
    resources/image/general_test/湘A53U19.jpg \
    resources/image/general_test/湘A5RM87.jpg \
    resources/image/general_test/湘A97971.jpg \
    resources/image/general_test/湘A9NU97.jpg \
    resources/image/general_test/湘A9YU86.jpg \
    resources/image/general_test/湘AA8516.jpg \
    resources/image/general_test/湘AED855.jpg \
    resources/image/general_test/湘AL8387.jpg \
    resources/image/general_test/湘AT1Y68.jpg \
    resources/image/general_test/湘AT3597.jpg \
    resources/image/general_test/湘AT8781.jpg \
    resources/image/general_test/湘ATL269.jpg \
    resources/image/general_test/湘AYN355.jpg \
    resources/image/general_test/湘F8ZS83.JPG \
    resources/image/general_test/湘G60009.jpg \
    resources/image/general_test/湘GR0L16.jpg \
    resources/image/general_test/皖A00T45.jpg \
    resources/image/general_test/皖A09T87.jpg \
    resources/image/general_test/皖A1T235.jpg \
    resources/image/general_test/皖A22T43.jpg \
    resources/image/general_test/皖A2F560.jpg \
    resources/image/general_test/皖A30123.jpg \
    resources/image/general_test/皖A45277.jpg \
    resources/image/general_test/皖A80003.jpg \
    resources/image/general_test/皖A80375.jpg \
    resources/image/general_test/皖A85501.jpg \
    resources/image/general_test/皖A85890.jpg \
    resources/image/general_test/皖A87271.jpg \
    resources/image/general_test/皖AA3610.jpg \
    resources/image/general_test/皖AH8331.jpg \
    resources/image/general_test/皖AJH155.jpg \
    resources/image/general_test/皖AK169H.jpg \
    resources/image/general_test/皖AL025S.jpg \
    resources/image/general_test/皖AS3165.jpg \
    resources/image/general_test/皖AT789S.jpg \
    resources/image/general_test/皖ATH859.jpg \
    resources/image/general_test/皖AUB816.jpg \
    resources/image/general_test/皖AX688A.jpg \
    resources/image/general_test/皖BBC666.jpg \
    resources/image/general_test/皖EZM618.jpg \
    resources/image/general_test/皖F71646.jpg \
    resources/image/general_test/皖M12288.jpg \
    resources/image/general_test/皖M69311.jpg \
    resources/image/general_test/皖P77222.jpg \
    resources/image/general_test/皖Q06417.jpg \
    resources/image/general_test/皖Q0686学.jpg \
    resources/image/general_test/皖Q15538.jpg \
    resources/image/general_test/皖Q18632.jpg \
    resources/image/general_test/皖Q19917.jpg \
    resources/image/general_test/皖Q80197.jpg \
    resources/image/general_test/皖QA2825.jpg \
    resources/image/general_test/粤A2HQ34.JPG \
    resources/image/general_test/粤A2TS00.JPG \
    resources/image/general_test/粤A5DP12.JPG \
    resources/image/general_test/粤A5J512.jpg \
    resources/image/general_test/粤A5PJ05.JPG \
    resources/image/general_test/粤A5Q951.jpg \
    resources/image/general_test/粤A82349.jpg \
    resources/image/general_test/粤A84266.JPG \
    resources/image/general_test/粤A89311.JPG \
    resources/image/general_test/粤A94372.JPG \
    resources/image/general_test/粤A961F3.jpg \
    resources/image/general_test/粤AA0825.JPG \
    resources/image/general_test/粤AAA379.jpg \
    resources/image/general_test/粤AAB457.JPG \
    resources/image/general_test/粤AAC044.jpg \
    resources/image/general_test/粤AAD348.jpg \
    resources/image/general_test/粤AAF230.JPG \
    resources/image/general_test/粤AB288Y.JPG \
    resources/image/general_test/粤AB2893.JPG \
    resources/image/general_test/粤AF9C00.JPG \
    resources/image/general_test/粤AK9331.jpg \
    resources/image/general_test/粤AL6212.jpg \
    resources/image/general_test/粤AV0U41.jpg \
    resources/image/general_test/粤B0K999.jpg \
    resources/image/general_test/粤B2757B.jpg \
    resources/image/general_test/粤B2LR57.jpg \
    resources/image/general_test/粤B3RS91.jpg \
    resources/image/general_test/粤B4051L.jpg \
    resources/image/general_test/粤B577QK.jpg \
    resources/image/general_test/粤B5PQ23.JPG \
    resources/image/general_test/粤B5W601.JPG \
    resources/image/general_test/粤B7VW40.jpg \
    resources/image/general_test/粤B901BF.jpg \
    resources/image/general_test/粤B972HL.jpg \
    resources/image/general_test/粤BA103N.jpg \
    resources/image/general_test/粤BA9H07.jpg \
    resources/image/general_test/粤BB867A.jpg \
    resources/image/general_test/粤BDB720.jpg \
    resources/image/general_test/粤BE24Q7.jpg \
    resources/image/general_test/粤BE609T.jpg \
    resources/image/general_test/粤BK33E3.jpg \
    resources/image/general_test/粤BP3T05.jpg \
    resources/image/general_test/粤BR75Y3.jpg \
    resources/image/general_test/粤BTT255.jpg \
    resources/image/general_test/粤BW44R6.jpg \
    resources/image/general_test/粤BZ756T.jpg \
    resources/image/general_test/粤BZ89M9.jpg \
    resources/image/general_test/粤CXE592.jpg \
    resources/image/general_test/粤E9R439.JPG \
    resources/image/general_test/粤OA2160.jpg \
    resources/image/general_test/粤OA9112.jpg \
    resources/image/general_test/粤OT9048.jpg \
    resources/image/general_test/粤SD050L.JPG \
    resources/image/general_test/粤SK903B.JPG \
    resources/image/general_test/粤TD1291.jpg \
    resources/image/general_test/粤VS1866.jpg \
    resources/image/general_test/粤X30479.JPG \
    resources/image/general_test/苏A0CP56.jpg \
    resources/image/general_test/苏A20Q03.jpg \
    resources/image/general_test/苏A36E80.jpg \
    resources/image/general_test/苏A66U71.jpg \
    resources/image/general_test/苏A6E176.jpg \
    resources/image/general_test/苏A75976.jpg \
    resources/image/general_test/苏A85Z95.jpg \
    resources/image/general_test/苏A9YP07.jpg \
    resources/image/general_test/苏AD6A99.jpg \
    resources/image/general_test/苏ADW072.jpg \
    resources/image/general_test/苏AHOG66.jpg \
    resources/image/general_test/苏AL926V.jpg \
    resources/image/general_test/苏AP0966.jpg \
    resources/image/general_test/苏AQ5B65.jpg \
    resources/image/general_test/苏AVW997.jpg \
    resources/image/general_test/苏B551QV.jpg \
    resources/image/general_test/苏B577CU.jpg \
    resources/image/general_test/苏BGG522.jpg \
    resources/image/general_test/苏BU5838.jpg \
    resources/image/general_test/苏CTF181.jpg \
    resources/image/general_test/苏DLA031.jpg \
    resources/image/general_test/苏E2Y256.jpg \
    resources/image/general_test/苏E75614.jpg \
    resources/image/general_test/苏EB68W9.jpg \
    resources/image/general_test/豫K91239.jpg \
    resources/image/general_test/豫S33909.jpg \
    resources/image/general_test/豫U00000.jpg \
    resources/image/general_test/赣A82F36.jpg \
    resources/image/general_test/赣A88888.jpg \
    resources/image/general_test/赣K11978.jpg \
    resources/image/general_test/辽B99999.jpg \
    resources/image/general_test/辽BG0D80.jpg \
    resources/image/general_test/辽BMW005.jpg \
    resources/image/general_test/辽C33333.jpg \
    resources/image/general_test/辽PE9218.jpg \
    resources/image/general_test/闽CPB592.jpg \
    resources/image/general_test/闽HB1508.jpg \
    resources/image/general_test/陕AD2N68.jpg \
    resources/image/general_test/陕AE8F80.jpg \
    resources/image/general_test/鲁A88888.jpg \
    resources/image/general_test/鲁B995EQ.jpg \
    resources/image/general_test/鲁BQG527.jpg \
    resources/image/general_test/鲁JRW350.jpg \
    resources/image/general_test/鲁KK5555.jpg \
    resources/image/general_test/鲁LD9016.jpg \
    resources/image/general_test/鲁Y44748.jpg \
    resources/image/general_test/黑A16341.jpg \
    resources/image/general_test/黑A1R272.jpg \
    resources/image/general_test/黑AB4444.jpg \
    resources/image/native_test/GroundTruth_others.xml \
    resources/image/native_test/GroundTruth_windows.xml \
    resources/image/native_test/car.jpg \
    resources/image/native_test/car1.jpg \
    resources/image/native_test/car3.jpg \
    resources/image/plate_detect.jpg \
    resources/image/plate_judge.jpg \
    resources/image/plate_locate.jpg \
    resources/image/plate_recognize.jpg \
    resources/image/test.jpg \
    resources/image/tmp/grayBINARY.jpg \
    resources/image/tmp/grayblure.jpg \
    resources/image/tmp/graygrad.jpg \
    resources/image/tmp/inputgray2.jpg \
    resources/image/tmp/phologyEx.jpg \
    resources/image/tmp/repaireimg1.jpg \
    resources/image/tmp/repaireimg2.jpg \
    resources/image/tmp/sobelSecSearch.jpg \
    resources/image/使用说明.txt \
    resources/result/Result.xml \
    resources/result/accuracy.txt \
    resources/result/gridSearch.txt \
    resources/result/plateGroundTruth.txt \
    resources/text/batch_test_menu \
    resources/text/chinese_mapping \
    resources/text/dev_team \
    resources/text/main_menu \
    resources/text/province_mapping \
    resources/text/test_menu \
    resources/text/thanks \
    resources/text/train_menu \
    resources/train/ann.7z \
    resources/train/annCh.7z \
    resources/train/annGray.7z \
    resources/train/svm.7z \


INCLUDEPATH += D:\opencv4.5.2\opencv\OpenCV-MinGW-Build-OpenCV-4.5.2-x64/include
LIBS += -L D:\opencv4.5.2\opencv\OpenCV-MinGW-Build-OpenCV-4.5.2-x64\x64\mingw\lib\libopencv_*.a

#INCLUDEPATH +=D:\vcpkg\vcpkg\installed\x64-windows\include
#INCLUDEPATH +=D:\OpenSSL-Win64\include

#LIBS += -LD:\OpenSSL-Win64\lib\VC\x64\MD -llibssl -llibcrypto
# 添加 jsoncpp 库文件搜索路径
# LIBS += -LD:\vcpkg\vcpkg\installed\x64-windows\lib \
#         -llibcurl \
#         -ljsoncpp
RESOURCES += \
    res.qrc

