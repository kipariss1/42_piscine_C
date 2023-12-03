ifconfig -a | grep ether | sed -r "s|ether ||" | sed -r "s|[a-z]* [0-9]*  \(.*\)$||" | tr -d " ";
