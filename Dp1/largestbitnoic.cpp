 	
	int longestBitonicSubarray(int *input, int n) {
		
	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
     	int* output = new int[n];
	output[0] = 1;
	for (int i = 1; i < n; i++) {
		output[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (input[j] >= input[i]) {
				continue;
			}
			int possibleAns = output[j] + 1;
			if (possibleAns > output[i]) {
				output[i] = possibleAns;
			}
		}
    }
       /* for(int i=0;i<n;i++)
            cout<<output[i]<<"\n ";
        */
        
        
        for (int i = 1; i < n; i++) {
		
        for (int j = i - 1; j >= 0; j--) {
			if (input[j] <=input[i]) {
				continue;
			}
			int possibleAns2 = output[j]+ 1;
			if (possibleAns2 > output[i]) {
				output[i] = possibleAns2;
			}
		}
        
	}
      //  for(int i=0;i<n;i++)
        //    cout<<output[i]<<" ";
        int best = 0;
	 for(int i=0;i<n;i++)
     {
		if (best < output[i]) {
			best = output[i];
		}
	}
	delete [] output;
	return best;
     	
     	
 	}


