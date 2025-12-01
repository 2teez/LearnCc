#!/usr/bin/env bash
# Date: 10 Jul, 2025
# Description: Make a file that can make a cpp file
# compile it and run.
# Author: omitida
#

## Help or usage function
# it display what the calling of the script is.
function usage() {
    filename="${0}"
    echo
    echo "Usage: ./${filename} <options> filename"
    echo
    echo "Avaliable Options:"
    echo "-a    : create a header file, with cpp file and main file."
    echo "-b    : debugging cpp file using gdb."
    echo "-d    : delete a file."
    echo "-g    : Create a generic cpp file."
    echo "-r    : Compile and Run a cpp file"
    echo "-R    : Compile and Run a cpp file with a choice cpp standard."
    echo "-h    : help."
}

# cpp start writeup
FILE="
// A complete C++ Program
#include <iostream>
#include <string>

int main(int argc, char** argv)
{

    std::string hello {\"Hello, World!\"};
    std::cout << hello << std::endl;

    return 0;
}
"

# creating a cpp file
function create_file() {
    filename="${1}"
    filext="${filename#*.}"

    # create a rust file
    rust_file="${filename}.rs"
    echo "
#![allow(dead_code, unused)]

fn main() {
  println!("Hello, World!");
}" > "${rust_file}"
    # make a file with cpp extension
    [[ "${filext}" == "${filename}" ]] && filename="${filename}.cpp"

    if [[ -e "${filename}" ]]; then
        echo "${filename}" "exist."
        printf "Do you want to overwrite it? [y|n]: "
        while read ans; do
            case "${ans,,}" in
                y)
                echo "// ${filename}" > "${filename}"
                printf "${FILE}" >> "${filename}"
                echo "${filename}" "is overwritten."
                break
                ;;
                n) exit 1
                ;;
                *) echo "can only you use 'y' or 'n'."
                continue
                ;;
            esac
        done
    else
        echo "// ${filename}" > "${filename}"
        echo "${FILE}" >> "${filename}"
    fi
}

# create a header file, cpp amd main.cpp
function header_file() {
   file="${1}"
   title="${file%.*}"
   header_file="${title}.hpp"
   echo "
#ifndef __"${title^^}"__
#define __"${title^^}"__
// include the structure of the header file

#include "\"${title}.inl\""

#endif //__"${title^^}"__
   " > "${header_file}"

  filename="${filename}.cpp"

  # create needed files
  echo "//#include \"${title}.hpp\"" > "${title}.inl"
  echo "#include \"${title}.hpp\"" > "${filename}"
  create_file "${filename%.*}_main.cpp" # make a main file also
}

if [[ "${#}" != 2 ]]; then
    usage
fi

optstring="a:b:d:g:r:R:h"

while getopts "${optstring}" opt; do
    case "${opt}" in
        a)
            filename="${OPTARG,,}"
            header_file "${filename}"
          ;;
        b)
            filename="${OPTARG}"
            file_o_run="${filename%.*}";
            extension="${filename#*.}"
            g++ -Wall -std=c++17  -o "${file_o_run}" "${filename}"
            chmod +x "${file_o_run}"
            gdb ./"${file_o_run}"
            rm ./"${file_o_run}"
        ;;
        d)
        filename="${OPTARG,,}"
        for file in $(ls); do
            if [[ "${filename}" = "${file}" ]]; then
                printf "Do you want to delete ${file}? [y|n]: "
                while read ans; do
                    case "${ans,,}" in
                        y) rm "${file}"
                           exit 0;;
                        n) break;;
                        *) printf "Can only use 'n' for no, and 'y' for yes.\n"
                        continue
                        ;;
                    esac
                done
            fi
        done

        ;;
        g)
          filename="${OPTARG,,}"
          create_file "${filename}"
          ./"${0}" -r "${filename}"
        ;;
        h) usage
           exit 1
        ;;
        R)
            filename="${OPTARG}"
            file_o_run="${filename%.*}";
            extension="${filename#*.}"
            if [[ "${extension}" == "rs" ]]; then
                rustc "${filename}" && ./"${file_o_run}" && rm "${file_o_run}"
                exit 0
            fi
            ## get the cpp standards
            default_std= #std=c++17
            while read -p "Enter a cpp standard of choice: " ans; do
                if [[ "${ans}" =~ ^[0-9]{2}$ ]]; then
                    default_std="c++${ans}";
                    echo "You are compiling with ${default_std} standard. Enter to continue..."
                    read
                    break
                fi
                echo "Invalid input. ${ans}. Only specify the year; 98, 03, 11, 17, etc."
            done
            g++ -Wall -std="${default_std}"  -o "${file_o_run}" "${filename}"
            chmod +x "${file_o_run}"
            ./"${file_o_run}"
            rm "${file_o_run}"
        ;;
        r)
            filename="${OPTARG}"
            file_o_run="${filename%.*}";
            extension="${filename#*.}"
            if [[ "${extension}" == "rs" ]]; then
                rustc "${filename}" && ./"${file_o_run}" && rm "${file_o_run}"
                exit 0
            fi
            g++ -Wall -std=c++17  -o "${file_o_run}" "${filename}"
            chmod +x "${file_o_run}"
            ./"${file_o_run}"
            rm "${file_o_run}"
        ;;
        *.*);;
    esac
done
