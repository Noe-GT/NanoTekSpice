# NanoTekSpice
Electronic circuits and components simulation.

## Documentation
- [**Project guidelines**](./documentation/nanotekspice_guidelines.pdf)
- [**Components schematics**](./documentation/schematics/)

## How to compile and launch
compile the project with
```bash
$ make
```

 run the program
```bash
$ ./nanotekspice config_file.nts
```

## Config file format (.nts)`
Use ```.chipsets:``` to declare components as: ```type name```

Example:

```
.chipsets:
input in_1
input in_2
output out
or gate
```

Use ```.links:``` to link components together as: ```name1:pin name2:pin```
Example:
```
.links:
in_1:1 gate:1
in_2:1 gate:2
out:1 gate:3
```
(see examples in [**config_examples**](./config_examples/))

### Available components:
- input
- output
- true
- false
- clock
- or
- and
- xor
- nor
- nand
- 4081
- 4071
- 4069
- 4030
- 4011
- 4001

## Contributors

| Contributor | GitHub Profile | Mail |
|-------------|---------------| ---------|
| <img src="https://avatars.githubusercontent.com/u/145701681?v=4" width="100" alt="Killian"> | [Killian](https://github.com/QUINTIN-Killian) | killian.quintin@epitech.eu
| <img src="https://avatars.githubusercontent.com/u/146707849?v=4" width="100" alt="Noe"> | [Noe](https://github.com/Noe-GT) | noe-daniel.gebert@epitech.eu

---
<div align="center">
  <img src="https://devfesttoulouse.fr/wp-content/uploads/2024/09/EPI-LOGO-ACCROCHE-2023-QUADRI.png" alt="Epitech Logo"
  width="400"
</div>