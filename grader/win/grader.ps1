$buildDir = ".\build"

# Define the path to the executable
$executable = "$buildDir\task$taskNumber.exe"

# Initialize total score and passed test count
$total_score = 0.0
$passed_tests = 0
$all_tests_passed = $true

$test_cases = ($test_cases -replace "`r`n", "`n")
$test_cases_output = ($test_cases_output -replace "`r`n", "`n")

# Display the running grader header
Write-Host ""
Write-Host -ForegroundColor White "--------------------------------------------------"
Write-Host -ForegroundColor White "|            Running Grader: Task $taskNumber            |"
Write-Host -ForegroundColor White "--------------------------------------------------"
Write-Host ""

# Run tests
for ($i = 0; $i -lt $test_cases.Length; $i++) {
  $grader_input = $test_cases[$i]
  $expected_output = $test_cases_output[$i]
  $output = ((Write-Output $grader_input | & $executable | Out-String) -replace "`r`n", "`n")
  $output = $output.Substring(0, $output.Length - 1)

  if ($LASTEXITCODE -eq 0) {
    Write-Host -ForegroundColor Green "Pass: Program exited zero"
  } else {
    Write-Host -ForegroundColor Red "Fail: Program did not exit zero"
  }

  if ($output -eq $expected_output) {
    Write-Host -ForegroundColor Green "Pass: Output is correct"
    $score = 10.0
    $total_score += $score
    $passed_tests++
  } else {
    Write-Host -ForegroundColor Red "Expected '$expected_output' but got: '$output'"
    $score = 0.0
    $all_tests_passed = $false
  }

  Write-Host "Test $(($i+1)) Score: $score/10"
  Write-Host ""
}

# Round total score to 1 decimal place
$total_score = [math]::Round($total_score, 1)

# Calculate the maximum possible score
$max_score = [math]::Round($test_cases.Length * 10, 1)

Write-Host -ForegroundColor Magenta "Total Score: $total_score/$max_score"
Write-Host -ForegroundColor Magenta "Passed Tests: $passed_tests/$($test_cases.Length)"
Write-Host ""

if ($all_tests_passed) {
  Write-Host -ForegroundColor White "All tests passed."
  Write-Host -ForegroundColor White "--------------------------------------------------"
  Write-Host -ForegroundColor White "|                Congratulations!                |"
  Write-Host -ForegroundColor White "|               Task $taskNumber Completed               |"
  Write-Host -ForegroundColor White "--------------------------------------------------"
}
else {
  Write-Host -ForegroundColor White "--------------------------------------------------"
  Write-Host -ForegroundColor White "|                      Oops!                     |"
  Write-Host -ForegroundColor White "|                Task $taskNumber Failed                 |"
  Write-Host -ForegroundColor White "--------------------------------------------------"
}

Write-Host ""

exit 0
