#!/bin/bash
# Define task number
taskNumber="2_1"

# Define test cases (assuming you populate this array as needed)
$test_cases = (
  "Hello World!"
  "Minecraft Evolution"
  "1234567890  "
  "A longer sentence to test."
  "   Last test case!    "
)

$test_cases_output = (
  "12"
  "19"
  "12"
  "26"
  "22"
)


# Define the path to the grader script
scriptPath="$(dirname "$0")/grader.sh"
buildDir="./build"

# Export arrays
echo "Exporting test cases to $buildDir/array_data_$taskNumber.sh..."
declare -p test_cases test_cases_output > "$buildDir/array_data_$taskNumber.sh"
# Run the grader script
/bin/bash "$scriptPath" "$taskNumber"