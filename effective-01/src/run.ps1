Write-Output "------------------- [ item 02 result ] ---------------------------"
g++ -E main.cpp -o out/item02.pre
$linenumber = 1
Get-Content out/item02.pre | ForEach-Object {
    if ($_ -match "1.1413") {
        Write-Output ("File: [out/item02.pre] Line [{0}]: {1}" -f $linenumber, $_)
    }
    if ($_ -match "AspectRatio") {
        Write-Output ("File: [out/item02.pre] Line [{0}]: {1}" -f $linenumber, $_)
    }
    $linenumber++
}

Write-Output "------------------------------------------------------------------"
g++ effective.cpp main.cpp -o out/item02
out/item02