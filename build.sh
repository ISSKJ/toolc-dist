#!/bin/bash

ARCH=$(uname -m)
OS=$(uname)
DIRECTORY=$(echo "$OS-$ARCH" | tr '[:upper:]' '[:lower:]')

function _do_build()
{
    mkdir -p $DIRECTORY
    for dir in `find ./src -type d -name 'tc.*'`
    do
        mkdir -p $dir/bin
        make -C $dir
        mv $dir/bin/*  $DIRECTORY/
        rm -rf $dir/bin
    done
}

function _do_clean()
{
    rm -rf $DIRECTORY/*
    for dir in `find ./src -type d -name 'tc.*'`
    do
        make clean -C $dir
    done
}

function _do_usage()
{
    echo "$0 [ build | clean ]"
}

case "$1" in
    "build")
        _do_build
        ;;
    "clean")
        _do_clean
        ;;
    *)
        _do_usage
        ;;
esac


