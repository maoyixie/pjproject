# Read Fuzzing.md located at the root of pjproject dir for build instructions

#Modify this to point to the PJSIP location.
PJBASE=../../

include $(PJBASE)/build.mak

TARGET=Fuzzing

JSON=fuzz-json
#add
JSON2=fuzz-json2

XML=fuzz-xml
#add
XML2=fuzz-xml2

SDP=fuzz-sdp
#add
SDP2=fuzz-sdp2

STUN=fuzz-stun
#add
STUN2=fuzz-stun2

SIP=fuzz-sip
#add
SIP2=fuzz-sip2

RTCP=fuzz-rtcp
DNS=fuzz-dns
H264=fuzz-h264
VPX=fuzz-vpx
HTTP=fuzz-http
URL=fuzz-url
URI=fuzz-uri
CRYPTO=fuzz-crypto

EXTFLAGS=-Wall -Werror

all: $(TARGET)

$(TARGET):
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(JSON).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(XML).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(SDP).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(STUN).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(SIP).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(RTCP).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(DNS).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(H264).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(VPX).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(HTTP).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(URL).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(URI).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(CRYPTO).c
	
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(JSON2).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(XML2).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(SDP2).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(STUN2).c
	$(CC) $(PJ_CFLAGS) $(EXTFLAGS) -c $(SIP2).c
	

	$(CXX) $(PJ_CFLAGS) -o $(JSON) $(JSON).o $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(XML)  $(XML).o  $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(SDP)  $(SDP).o  $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(STUN) $(STUN).o $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(SIP)  $(SIP).o  $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(RTCP) $(RTCP).o $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(DNS)  $(DNS).o  $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(H264) $(H264).o $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(VPX)  $(VPX).o  $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(HTTP) $(HTTP).o $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(URL)  $(URL).o  $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(URI)  $(URI).o  $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)

	$(CXX) $(PJ_CFLAGS) -o $(JSON2)  $(JSON2).o  $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(XML2)  $(XML2).o  $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(SDP2)  $(SDP2).o  $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(STUN2)  $(STUN2).o  $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)
	$(CXX) $(PJ_CFLAGS) -o $(SIP2)  $(SIP2).o  $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE)


	$(CXX) $(PJ_CFLAGS) -o $(CRYPTO) $(CRYPTO).o $(PJ_LDFLAGS) $(PJ_LDLIBS) $(LDFLAGS) $(LIB_FUZZING_ENGINE) -lssl -lcrypto -lz

clean:
	rm $(JSON) $(JSON2) $(XML) $(XML2) $(SDP) $(SDP2) $(STUN) $(STUN2) $(SIP) $(SIP2) $(RTCP) $(DNS) $(H264) $(VPX) $(HTTP) $(URL) $(URI) $(CRYPTO) *.o
