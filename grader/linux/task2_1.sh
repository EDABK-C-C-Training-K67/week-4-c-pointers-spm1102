#!/bin/bash
# Define task number
taskNumber="3_1"

# Define test cases (assuming you populate this array as needed)
$test_cases = (
  "0" 
  "-1"
  "12"
  "255"
  "1024"
  "-1024"
  "2147483647"
  "-2147483648"
  "1987654321"
  "-1987654321"
)

$test_cases_output = (
  "00000000000000000000000000000000"
  "11111111111111111111111111111111"
  "00000000000000000000000000001100"
  "00000000000000000000000011111111"
  "00000000000000000000010000000000"
  "11111111111111111111110000000000"
  "01111111111111111111111111111111"
  "10000000000000000000000000000000"
  "01110110011110010011001010110001"
  "10001001100001101100110101001111"
)


# Define the path to the grader script
scriptPath="$(dirname "$0")/grader.sh"
buildDir="./build"

# Export arrays
echo "Exporting test cases to $buildDir/array_data_$taskNumber.sh..."
declare -p test_cases test_cases_output > "$buildDir/array_data_$taskNumber.sh"
# Run the grader script
/bin/bash "$scriptPath" "$taskNumber"