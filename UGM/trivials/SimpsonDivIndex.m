% The following matlab function is used for claculation of Simpson's Index of 
% Diversity and 95% Confidence Interval
%
%    Copyright (C) 2009  UMMI@IMM
%
%    This file is part of Comparing Partitions website <http://www.comparingpartitions.info/>.    
%    Comparing Partitions website is free software: you can redistribute it and/or modify
%    it under the terms of the GNU General Public License as published by
%    the Free Software Foundation, either version 3 of the License, or
%    (at your option) any later version.
%
%    This program is distributed in the hope that it will be useful,
%    but WITHOUT ANY WARRANTY; without even the implied warranty of
%    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%    GNU General Public License for more details.
%
%    You should have received a copy of the GNU General Public License
%    along with this program.  If not, see <http://www.gnu.org/licenses/>.
%
function [SID,CI,s]=SimpsonDivIndex(invec)
%function SID=SimpsonDivIndex(invec)
%invec= vector with data cluster defined
%Joao Carrico 10 August 2005
%jcarrico@algos.inesc-id.pt

[a,b,c]=unique(invec);
N=length(invec);%total strains in population
s=length(a);%Total types in population
tc=histc(c,[1:max(c)]);%Total strains per type
SumTc=sum(tc.*(tc-1));
SID=1-(SumTc/(N*(N-1)));%Simpson's Index of Diversity
fTc=tc./N;%type frequency
SumfTc3=sum(fTc.^3);
SumfTc2=sum(fTc.^2);

s2=(4/N)*(SumfTc3-SumfTc2^2);%variance for SID values

CI=[SID-2*sqrt(s2) SID+2*sqrt(s2)];%95% Confidence Interval

