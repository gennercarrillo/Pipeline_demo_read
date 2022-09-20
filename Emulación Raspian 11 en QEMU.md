Referencia: https://blog.agchapman.com/using-qemu-to-emulate-a-raspberry-pi/

/* Proceso desarrollado sobre UBUNTU 20.04

1. Instalar QEMU

#: $sudo apt-get install qemu-system-arm
 
2. Descargar raspbian de la pagina oficial https://www.raspberrypi.org/downloads/raspbian/
para el caso se instalo Rasbpian 11 / 32 bits con Desktop

2022-09-06-raspios-bullseye-armhf.img.xz

3. Si no tiene instalado unxz, instalarlo

#: $sudo apt-get install unxz

4. Descomprimir el archivo de imagen (tarda un poco)

#: $unxz 022-09-06-raspios-bullseye-armhf.img.xz

5. Descargar el archivo de Kernel para raspberry recomendado(kernel-qemu-4.4.34-jessie)
https://github.com/dhruvvyas90/qemu-rpi-kernel/raw/master/kernel-qemu-4.4.34-jessie

Nota: debe quedar en la misma carpeta de la imagen

6. Reformatear y expandirla imagen descargada

#: qemu-img convert -f raw -O qcow2 ACA_NOMBRE_DE_ARCHIVO.img raspbian-stretch-lite.qcow
#: qemu-img resize raspbian-stretch-lite.qcow +20G

7. Ejecutar el siguiente comando y esperar que cargue:

#: sudo qemu-system-arm \
-kernel ./kernel-qemu-4.4.34-jessie \
-append "root=/dev/sda2 panic=1 rootfstype=ext4 rw" \
-hda raspbian-stretch-lite.qcow \
-cpu arm1176 -m 256 \
-M versatilepb \
-no-reboot \
-serial stdio \
-net nic -net user \
-net tap,ifname=vnet0,script=no,downscript=no

nota: las descripciones de cada argumento se pueden ver en el archivo de referencia



/****************************COMPILAR PROTOBUF PARA HOST**********

https://developer.arm.com/documentation/102649/2205/Before-you-begin

Repos para protobuf
sudo apt-get install git
sudo apt-get install scons
sudo apt-get install gcc-arm-linux-gnueabihf
sudo apt-get install g++-arm-linux-gnueabihf
sudo apt-get install curl 
sudo apt-get install autoconf
sudo apt-get install libtool
sudo apt-get install cmake
sudo apt-get install g++
sudo apt-get install wget
sudo apt-get install unzip
sudo apt-get install xxd

/***
#git clone -b v3.12.0 https://github.com/google/protobuf.git
#cd $BASEDIR/protobuf
#git submodule update --init --recursive
#./autogen.sh
#./configure --prefix=$BASEDIR/protobuf-host
Se sugiere añadir espacio en el swap para cuando se va a ejecutar el make
#make (tiempo estimado (>5 horas))
#make install
#make clean


/****************************COMPILAR PROTOBUF PARA Raspberry**********
./configure --prefix=$BASEDIR/protobuf-arm --host=arm-linux CC=arm-linux-gnueabihf-gcc CXX=arm-linux-gnueabihf-g++ --with-protoc=$BASEDIR/protobuf-host/bin/protoc
make
make install



/************AÑADIR MEMORIA VIRTUAL (ram) PARA MAKE*******
1. Iremos a la terminal más cercana e iremos a raíz con el comando:
#: $ cd /
2. Crearemos un fichero de 1GB que tendrá la función de ser memoria SWAP.

#: $ sudo dd if=/dev/zero of=swapfile bs=1M count=1000
3. Formatearemos dicho archivo para ser memoria SWAP

4. Darle permisos al archivo
#: chmod -R 0600 swapfile

#: $ sudo mkswap swapfile
4. Activaremos dicho archivo con el comando swapon

#: $ sudo swapon swapfile

REPETIR POR SI NO MONTA AL INICIO
#:sudo swapoff swapfile
#:sudo mkswap swapfile
#:sudo swapon swapfile

/******Instalart Json -c

sudo apt-get install libjson-c-dev







