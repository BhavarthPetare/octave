% Implementation of (6,3) Linear Block Code
pkg load communications
clc;
clear all;
close all;
% Generator matrix G
G = [1 0 0 0 1 1;
0 1 0 1 0 1;
0 0 1 1 1 0];
% Number of message bits
k = 3;
% Generate all possible 3-bit messages
M = de2bi(0:(2^k - 1), k, 'left-msb');
disp('All possible message vectors (M):');
disp(M);
% Compute codewords
C = mod(M * G, 2);
disp('All possible code vectors (C):');
disp(C);
