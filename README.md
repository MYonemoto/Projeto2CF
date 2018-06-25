# Projeto2CF

1. Objetivo

O projeto construído para o segundo projeto da disciplina de Computação Física deve conter a maioria dos requisitos listados a seguir:

- Transdutores: Sensor e atuador;

- Microcontrolador;

- Software controlador;

- Web (browser ou app);

- Banco de dados;

Dessa forma, o objetivo do projeto construído foi criar um detector de ações, utilizando atuadores e sensores para tal detecção. Esse projeto pode ser utilizado em casas ou em qualquer ambiente que necessita de segurança e supervisão do local.

2. Componentes

Os componentes utilizados neste projeto foram:

- 1 arduino Uno;

- 1 laser (atuador);

- 1 sensor de movimento;

- 1 sensor de proximidade;

- 1 sensor de luminosidade;

- 1 Ethernet Shield.

Abaixo em subseções será mostrado como cada componente foi utilizado neste projeto.

2.1 Laser

O laser é um componente que funciona como atuador. Neste projeto, ele ficará apontado para um sensor de luminosidade, na qual quando for detectado uma baixa luminosidade, a atividade será notificada.

2.2 Sensor de Movimento

O sensor de movimento, como o próprio nome sugere, é um sensor capaz de detectar qualquer movimento que esteja em uma área de até 7 metros. Caso haja a detecção de algum movimento, a atividade será notificada.

2.3 Sensor de Proximidade

O sensor de proximidade é um componente bastante comum em projetos com Arduino. Esse sensor permite leituras de distâncias entre 2cm e 4m. Neste projeto, é utilizado também para detecção, então quando algo entrar no alcance do sensor, será notificado uma atividade para o usuário.

2.3 Sensor de Luminosidade

O sensor de luminosidade é um componente que funciona através da intensidade da luz. Neste projeto, a luz é o laser. Então, como falado anteriormente, quando algo passar no laser, a luminosidade irá diminuir, gerando uma notificação para o usuário.

2.4 Ethernet Shield

O ethernet shield é um componente que permite que uma placa Arduino faça conexão com a Internet. Este componente é necessário para o projeto pelo fato de que utilizamos a web para mostrar e salvar as notificações.

3. Funcionamento

Como já dito anteriormente, este projeto é um detector de ações, utilizando sensores de movimento, proximidade e de luminosidade. Porém, nao basta apenas detectar essas ações e não gerar um alerta. Dessa forma, utilizando a plataforma Firebase, essas ações detectadas são salvas para que o usuário possa saber quando houve tal ação. Sem entrar em muitos detalhes, o Firebase é uma plataforma de desenvolvimento mobile e web, na qual disponibiliza diversos serviços diferentes que auxiliam no desenvolvimento e gerenciamento de aplicativos.

Heroku, Firebase
