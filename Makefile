BOOST=/usr/local/boost/1.49.0

CC=gcc
CXX=g++
CPPFLAGS= \
    -I$(BOOST)/include

CFLAGS= \
    -g \
    -O0 \
    -std=c99 \
    -Wall \
    -Werror

CXXFLAGS= \
    -g \
    -O0 \
    -Wall \
    -Werror

LDFLAGS=

LDLIBS= \
    -L$(BOOST)/lib \
    -lrt

TARGETS= \
    derived_class \
    reverse_slist \
    string_reverse \
    bubble_sort \
    quicksort_in_place \
    traverse_btree \
    sum_of_combinations \
    stanford_rec_permute \
    stanford_rec_subsets \
    my100 \
    100

all: ${TARGETS}

clean:
	rm -f ${TARGETS}
