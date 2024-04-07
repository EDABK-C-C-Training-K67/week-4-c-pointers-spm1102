#!/bin/bash
# Define task number
taskNumber="2_2"

# Define test cases (assuming you populate this array as needed)
$test_cases = (
  "0.0"
  "-0.0"
  "3.5"
  "1.0"
  "-1.0"
  "123456.123456"
  "-123456.123456"
  "1.175494"
  "-1.175494"
  "0.000001"
)

$test_cases_output = (
  "00000000000000000000000000000000"
  "10000000000000000000000000000000"
  "01000000011000000000000000000000"
  "00111111100000000000000000000000"
  "10111111100000000000000000000000"
  "01000111111100010010000000010000"
  "11000111111100010010000000010000"
  "00111111100101100111011010010110"
  "10111111100101100111011010010110"
  "00110101100001100011011110111101"
)


# Define the path to the grader script
scriptPath="$(dirname "$0")/grader.sh"
buildDir="./build"

# Export arrays
echo "Exporting test cases to $buildDir/array_data_$taskNumber.sh..."
declare -p test_cases test_cases_output > "$buildDir/array_data_$taskNumber.sh"
# Run the grader script
/bin/bash "$scriptPath" "$taskNumber"