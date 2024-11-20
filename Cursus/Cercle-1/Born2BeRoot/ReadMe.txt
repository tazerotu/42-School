<qemu:commandline>
  <qemu:arg value='-netdev'/>
  <qemu:arg value='user,id=mynet.0,net=10.0.10.0/24,hostfwd=tcp::22222-:4242'/>
  <qemu:arg value='-device'/>
  <qemu:arg value='rtl8139,netdev=mynet.0'/>
</qemu:commandline>
 
 
xmlns:qemu='http://libvirt.org/schemas/domain/qemu/1.0'
