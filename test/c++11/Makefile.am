
noinst_PROGRAMS = flushproto_test carrier_test

AM_CXXFLAGS = -Wno-deprecated-declarations

flushproto_test_SOURCES = flushproto_test.cc
flushproto_test_CXXFLAGS = $(AM_CXXFLAGS) -I $(top_srcdir)/src/c++11 -I $(top_srcdir)/src/c++11/lightstep $(protobuf_CFLAGS)
flushproto_test_LDADD = ../../src/c++11/liblightstep_core_cxx11.la
flushproto_test_LDFLAGS = $(protobuf_LIBS)

carrier_test_SOURCES = carrier_test.cc
carrier_test_CXXFLAGS = $(AM_CXXFLAGS) -I $(top_srcdir)/src/c++11 -I $(top_srcdir)/src/c++11/lightstep $(protobuf_CFLAGS)
carrier_test_LDADD = ../../src/c++11/liblightstep_core_cxx11.la
carrier_test_LDFLAGS = $(protobuf_LIBS)

EXTRA_DIST = \
	dropbox_json/LICENSE.txt

noinst_HEADERS = \
	test.h \
	dropbox_json/json11.hpp \
	zintinio_happyhttp/happyhttp.h


TESTS = flushproto_test carrier_test

if ENABLE_GRPC

noinst_PROGRAMS += tracer_test

tracer_test_SOURCES = tracer_test.cc
tracer_test_CXXFLAGS = $(AM_CXXFLAGS) -I $(top_srcdir)/src/c++11 -I $(top_srcdir)/src/c++11/lightstep $(grpc_CFLAGS) $(protobuf_CFLAGS)
tracer_test_LDADD = ../../src/c++11/liblightstep_grpc_cxx11.la 
tracer_test_LDFLAGS = $(protobuf_LIBS) $(grpc_LIBS)++

noinst_PROGRAMS += cppclient

# Note: See github.com/lightstep-benchmarks to execute this test program.
cppclient_SOURCES = \
	cppclient.cc \
	dropbox_json/json11.cpp \
	zintinio_happyhttp/happyhttp.cpp

cppclient_CXXFLAGS = $(AM_CXXFLAGS) -I $(top_srcdir)/src/c++11 -I $(top_srcdir)/src/c++11/lightstep $(grpc_CFLAGS) $(protobuf_CFLAGS)
cppclient_LDADD = ../../src/c++11/liblightstep_grpc_cxx11.la
cppclient_LDFLAGS = $(protobuf_LIBS) $(grpc_LIBS)++

TESTS += tracer_test
endif
