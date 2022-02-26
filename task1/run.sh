#!/usr/bin/env bash
while [ -n "$1" ]
do
case $1 in
	'--input_folder')
		input_folder=$2;;
	'--extension')
		extension=$2;;
	'--backup_folder')
		backup_folder=$2;;
	'--backup_archive_name')
		backup_archive_name=$2;;
	esac
shift 2
done
mkdir $backup_folder
current_directory=$PWD
find $input_folder -name "*.$extension" -exec cp --backup=numbered {} $current_directory/$backup_folder \;
tar -zcvf $backup_archive_name -P $backup_folder >/dev/null
echo "done"
