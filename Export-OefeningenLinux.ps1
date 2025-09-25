<#
.SYNOPSIS
Maak een Linux-vriendelijke export van alle Visual Studio oefenprojecten.

.DESCRIPTION
Dit script kopieert de volledige projectstructuur van C_Fundamentals_Exercises,
maar filtert enkel de bronbestanden (.c, .h). 
De nieuwe structuur wordt geplaatst in C_Fundamentals_Exercises_linux,
naast de originele map. De originele map blijft onaangetast.

Gebruik -Force om bestaande bestanden te overschrijven.
Gebruik -Flat om alle bestanden in één map te zetten in plaats van de structuur te behouden.
#>

[CmdletBinding()]
param(
    [switch]$Force, # Overschrijf bestaande bestanden indien aanwezig
    [switch]$Flat   # Alle bestanden in één map gooien
)

# Padinstellingen
$Root = Get-Location
$SourceDir = Join-Path $Root "C_Fundamentals_Exercises"
$Destination = Join-Path $Root "C_Fundamentals_Exercises_linux"

# Check bronmap
if (-not (Test-Path $SourceDir)) {
    Write-Error "Bronmap niet gevonden: $SourceDir"
    exit 1
}

# Doelmap aanmaken indien nodig
if (-not (Test-Path $Destination)) {
    New-Item -ItemType Directory -Path $Destination | Out-Null
    Write-Host "Aangemaakt: $Destination"
}

# Zoek alle bronbestanden
$files = Get-ChildItem -Path $SourceDir -Recurse -Include *.c, *.h

foreach ($file in $files) {
    if ($Flat) {
        # In flat mode → <ProjectNaam>_<Bestandsnaam>.ext
        $project = Split-Path $file.DirectoryName -Leaf
        $newName = "${project}_$($file.Name)"
        $destFile = Join-Path $Destination $newName
        $destDir = $Destination
    }
    else {
        # Structuur behouden
        $relativePath = $file.FullName.Substring($SourceDir.Length).TrimStart('\', '/')
        $destFile = Join-Path $Destination $relativePath
        $destDir = Split-Path $destFile -Parent
    }

    # Maak doelmap indien nodig
    if (-not (Test-Path $destDir)) {
        New-Item -ItemType Directory -Path $destDir -Force | Out-Null
    }

    # Bestaan-check
    if ((Test-Path $destFile) -and (-not $Force)) {
        Write-Warning "Bestand bestaat al, overslaan: $destFile (gebruik -Force om te overschrijven)"
        continue
    }

    Copy-Item $file.FullName $destFile -Force
    Write-Host "Gekopieerd: $($file.FullName) → $destFile"
}

Write-Host "Klaar! Alle C en headerbestanden staan nu in: $Destination"
