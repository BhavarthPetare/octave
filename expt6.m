initial_sequence = [1 1 1];
length = 7;
register = initial_sequence;
feedback = 0;
feedback_taps = [1 3];
pn = zeros(1,7);
for i = 1:7
    pn(i) = register(end);
    feedback = xor(register(feedback_taps(1)) , register(feedback_taps(2)));
    register = [feedback register(1:end-1)];
end
disp(pn);

% property verification
%balance property

numOnes = sum(pn == 1);
numZeros = sum(pn == 0);
if (numOnes > numZeros)
    disp('Balance property verified');
else
    disp('Balance property not verified');
end
% run property

runs = [];
run_length = [];
cur = pn(1);
count = 1;
for i = 2:7
    if (cur == pn(i))
        count = count + 1;
        cur = pn(i);
    else
        run_length(end + 1) = count;
        runs(end+1) = i;
        cur = pn(i);
        count = 1;
    end
end

disp ("runlengths: ");
disp(run_length);
