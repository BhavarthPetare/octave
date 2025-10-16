% Given
Tb = 5e-3;         % bit duration (s)
Rc = 1e6;          % chipping rate (chips/s)
Q_val = 4.25;      % from Q(4.25)=1e-5

% Calculations
Rb = 1/Tb;
Gp = Rc / Rb;                      % processing gain (linear)
Gp_dB = 10*log10(Gp);

EbN0 = (Q_val^2)/2;                % from sqrt(2*Eb/N0)=Q_val
EbN0_dB = 10*log10(EbN0);

JoverP_linear = Gp / EbN0;
JoverP_dB = 10*log10(JoverP_linear);

% Display
fprintf('Rb = %.2f bits/s\n', Rb);
fprintf('Processing gain Gp = %.4g (linear) = %.2f dB\n', Gp, Gp_dB);
fprintf('Eb/N0 = %.6f (linear) = %.3f dB\n', EbN0, EbN0_dB);
fprintf('J/P (linear) = %.4g\n', JoverP_linear);
fprintf('Jamming margin = %.2f dB\n', JoverP_dB); 
