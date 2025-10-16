elc;

clear,

close all;

%--Load Required Package...

pkg load signal; % Needed for xcorr()

%--- PARAMETERS...

n=3; % Number of stages

taps [31]; % Feedback taps (s3 XOR 51)

initial_state = [1 1 1]; % Initial state of LFSR

num_bits = 2^n-1; % Maximal length = 7

%-LFSR SIMULATION ...

state initial_state;

mseq= zeros(1, num_bits);

for i = 1:num_bits

mseq(i) = state(end); % Output = rightmost bit (s1)

feedback=mod(sum(state (taps)), 2), % XOR of tapped bits

state = [feedback state(1:end-1)], % Shift right

end

%---DISPLAY---

disp('Generated Maximum Length Sequence (m-sequence):');

disp(mseq);

%--- PLOT THE SEQUENCE

figure;

stem(mseq, 'filled');

xlabel('Sample Index');

ylabel('Output Bit');

title('Generated Maximum Length Sequence (m-sequence)");

grid on;

Step 2: Verify Properties of m-Sequence

% The sequence repeats after 2^n-1=7 bits.

period = length(mseq);

disp(['Period of the sequence:', num2str(period)]);

%--- Step 3: Balance Property ---

% Number of 1's Number of O's + 1

num_ones = sum(mseq);

num_zeros period - num_ones;

disp(['Number of 1s:', num2str(num_ones)]);

disp(['Number of Os: ', num2str(num_zeros)]);

%Step 4: Autocorrelation Property ---

mseq_bipolar = 2*mseq-1; % Convert 0->-1, 1->1

r=xcorr(mseq_bipolar, 'coeff'); % Normalized autocorrelation

figure;

stem(r);

xlabel('Lag');

ylabel('Autocorrelation');

title('Autocorrelation of m-sequence');

grid on;
