cd ~/Projects/Sevsu/VKR/project/idemix-network 
export PATH=${PWD}/../bin:$PATH
./network.sh down
./network.sh up createChannel -c zkp -ca

cd ~/Projects/Sevsu/VKR/project/backend 
export JAVA_HOME=/usr/lib/jvm/jdk-22-oracle-x64/
mvn spring-boot:run

cd ~/Projects/Sevsu/VKR/project/frontend
npm start