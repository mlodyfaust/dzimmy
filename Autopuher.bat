@ECHO OFF
cd C:\Users\Micky\Desktop\New project
git pull

:: Check if the first three letters of %DATE% are "Sat" or "Sun"
echo %DATE% | findstr /B "Sat Sun" >nul && (
    echo It's the weekend, skipping Git push.
    exit /b
)

:: Generate a random number between 1 and 8
SET /A PUSH_COUNT=%RANDOM% %% 8 + 1

ECHO Pushing %PUSH_COUNT% times...

:: Loop to push multiple times
FOR /L %%i IN (1,1,%PUSH_COUNT%) DO (
    ECHO %DATE% %TIME% >> log.txt
    git add .
    git commit -m "auto push %%i/%PUSH_COUNT%"
    git push
)

timeout 1 >nul
exit