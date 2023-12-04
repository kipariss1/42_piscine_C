iter=0; ls -l | while read -r l; do if [ $((iter%2)) -ne 0 ]; then echo "$l"; fi; iter=$((iter+1)); done;
