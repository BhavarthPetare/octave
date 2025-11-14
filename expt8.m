clc;
clear;
close all;

G = [
  1 0 0 0 1 1;
  0 1 0 1 0 1;
  0 0 1 1 1 0;
];

k = 3;

M = de2bi(0:(2^k - 1), k, 'left-msb');
disp("All possible message vectors(M):");
disp(M);

C=mod(M*G, 2);
disp("All possible code vectors (C):");
disp(C);
