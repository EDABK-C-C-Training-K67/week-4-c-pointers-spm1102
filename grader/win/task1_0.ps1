$scriptPath = "$PSScriptRoot\grader.ps1"
$taskNumber = "1_0"

# Define test cases
$test_cases = @(
  "Hello World!",
  "Minecraft Evolution",
  "1234567890  ",
  "A longer sentence to test.",
  "   Last test case!    "
)

$test_cases_output = @(
  "12",
  "19",
  "12",
  "26",
  "22"
)


& $scriptPath