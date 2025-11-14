tb = 5e-3;
rc = 1e6;
qval = 4.25;
rb = 1 / tb;

processing_gain = rc/rb
gain_db = 10*log10(processing_gain);


eb_no = (qval^2)/2  % val = eb/n0
eb_no_db = 10*log10(eb_no);

jamming = processing_gain/eb_no;
jamming_db = 10*log10(jamming);

fprintf("Processing gain = %.4g(linear)\n", processing_gain);
fprintf("Eb/N0 = %.6f(linear)\n", eb_no);
fprintf("Jamming margin = %.2f dB \n", jamming_db);
