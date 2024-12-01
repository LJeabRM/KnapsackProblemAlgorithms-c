@echo off
echo ====================================================================================
echo This algorithm may run for longer durations to produce better results.
echo The 'time limit' determines how long the algorithm will run.
echo A higher time limit might give the algorithm more time to find an optimal solution.
echo.

set /p time_limit="Please provide the time limit for the algorithm (in seconds): "
set input_file="knapsack1000.txt"

Project-main.exe %time_limit% %input_file%

pause
