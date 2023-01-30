<div align="center">

[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](LICENSE)
[![Speed](https://img.shields.io/static/v1.svg?label=Testing&message=High-speed%20&color=green)](#)
[![AFM](https://img.shields.io/static/v1.svg?label=Method&message=alignment-free&color=yellow)](#)

</div>

<p align="center"><img src="imgs/logo_black.png" alt="SynTegra" width="250" border="0" /></p>
<p align="center">
<b>A computational tool for simulation of viral synthetic integrations</b> 
</p>

<p align="justify">
This method provides the ability of fast simulation of viral synthetic integrations. SynTegra is implemented in C language, is flexible for multiple synthetic integration applications, and does not contain external dependencies. The tool accepts any sequences in FASTA format.
</p>

## Installation

### Conda
Install [Miniconda](https://docs.conda.io/en/latest/miniconda.html), then run the following:
```bash
conda install -y -c bioconda syntegra
```

### CMake via Git

Otherwise, CMake is needed for installation (http://www.cmake.org/). You can download it directly from http://www.cmake.org/cmake/resources/software.html or use an appropriate packet manager. If the system does not have cmake and git, please install it using the following

<pre>
sudo apt-get install cmake git
</pre>

After, the following instructions describe the procedure to install, compile and run SynTegra:
<pre>
git clone https://github.com/cobilab/syntegra.git
cd syntegra/src/
cmake .
make
</pre>

## Execution

### Run SynTegra

Run SynTegra tool with
<pre>
SynTegra --host host.fa --virus virus.fa > out.fasta;
</pre>

## Parameters

To see the possible options type
<pre>
SynTegra
</pre>
or
<pre>
SynTegra -h
</pre>

## Citation ##

On using this software/method please cite:

* pending

## Issues ##

For any issue let us know at [issues link](https://github.com/cobilab/syntegra/issues).

## License ##

GPL v3.

For more information:
<pre>http://www.gnu.org/licenses/gpl-3.0.html</pre>

