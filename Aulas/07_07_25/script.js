let scene, camera, renderer, controls;
let temperatura3D, umidade3D, luminosidade3D;
let dadosArray = [];

init();
animate();

function init() {
    scene = new THREE.Scene();
    scene.background = new THREE.Color(0xf5f7fa);
    
    camera = new THREE.PerspectiveCamera(60, window.innerWidth / (window.innerHeight * 0.5), 0.1, 1000);
    camera.position.set(0, 10, 20);
    
    renderer = new THREE.WebGLRenderer({ antialias: true });
    renderer.setSize(document.getElementById('dashboard3D').clientWidth, 400);
    document.getElementById('dashboard3D').appendChild(renderer.domElement);
    
    controls = new THREE.OrbitControls(camera, renderer.domElement);
    controls.enableDamping = true;
    controls.dampingFactor = 0.05;
    
    const ambientLight = new THREE.AmbientLight(0xffffff, 0.5);
    scene.add(ambientLight);
    
    const directionalLight = new THREE.DirectionalLight(0xffffff, 0.8);
    directionalLight.position.set(1, 1, 1);
    scene.add(directionalLight);
    
    createBase();
    createAxisLabels();
    processData();
    
    window.addEventListener('resize', onWindowResize);
}

function createBase() {
    const baseGeometry = new THREE.PlaneGeometry(25, 15);
    const baseMaterial = new THREE.MeshLambertMaterial({ 
        color: 0xffffff,
        side: THREE.DoubleSide,
        transparent: true,
        opacity: 0.8
    });
    const base = new THREE.Mesh(baseGeometry, baseMaterial);
    base.rotation.x = Math.PI / 2;
    base.position.y = -0.1;
    scene.add(base);
    
    const gridHelper = new THREE.GridHelper(25, 25, 0x888888, 0xcccccc);
    gridHelper.position.y = 0;
    scene.add(gridHelper);
}

function createAxisLabels() {
    const xAxis = new THREE.Mesh(
        new THREE.BoxGeometry(20, 0.1, 0.1),
        new THREE.MeshBasicMaterial({ color: 0x666666 })
    );
    xAxis.position.set(0, 0, -7);
    scene.add(xAxis);
    
    const yAxis = new THREE.Mesh(
        new THREE.BoxGeometry(0.1, 10, 0.1),
        new THREE.MeshBasicMaterial({ color: 0x666666 })
    );
    yAxis.position.set(-10, 5, -7);
    scene.add(yAxis);
}

function processData() {
    if (!dadosSensores || dadosSensores.length === 0) return;
    
    const latestData = dadosSensores[0];
    updateInfoCards(latestData);
    
    temperatura3D = new THREE.Group();
    umidade3D = new THREE.Group();
    luminosidade3D = new THREE.Group();
    
    scene.add(temperatura3D);
    scene.add(umidade3D);
    scene.add(luminosidade3D);
    
    const maxDados = Math.min(dadosSensores.length, 20);
    const spacing = 20 / maxDados;
    
    for (let i = 0; i < maxDados; i++) {
        const dado = dadosSensores[i];
        const xPos = -10 + (i * spacing);
        
        dadosArray.push({
            temperatura: dado.temperatura,
            umidade: dado.umidade,
            luminosidade: dado.luminosidade,
            xPos: xPos
        });
        
        criarBarraTemperatura(xPos, dado.temperatura);
        criarBarraUmidade(xPos, dado.umidade);
        criarEsferaLuminosidade(xPos, dado.luminosidade);
    }
}

function criarBarraTemperatura(x, valor) {
    const altura = valor / 10;
    const geometria = new THREE.BoxGeometry(0.4, altura, 0.4);
    const cor = valor > 30 ? 0xff5252 : 0x3498db;
    const material = new THREE.MeshLambertMaterial({ color: cor });
    const barra = new THREE.Mesh(geometria, material);
    barra.position.set(x, altura/2, -5);
    temperatura3D.add(barra);
}

function criarBarraUmidade(x, valor) {
    const altura = valor / 10;
    const geometria = new THREE.BoxGeometry(0.4, altura, 0.4);
    const cor = valor < 30 ? 0xff5252 : 0x2ecc71;
    const material = new THREE.MeshLambertMaterial({ color: cor });
    const barra = new THREE.Mesh(geometria, material);
    barra.position.set(x, altura/2, -3);
    umidade3D.add(barra);
}

function criarEsferaLuminosidade(x, valor) {
    const tamanho = Math.max(0.1, Math.min(0.8, valor / 1000));
    const geometria = new THREE.SphereGeometry(tamanho, 16, 16);
    const intensidade = Math.min(1, valor / 1000);
    const cor = new THREE.Color(1, 1, intensidade * 0.5);
    const material = new THREE.MeshPhongMaterial({ 
        color: cor,
        emissive: cor,
        emissiveIntensity: intensidade,
        shininess: 100
    });
    const esfera = new THREE.Mesh(geometria, material);
    esfera.position.set(x, tamanho + 0.1, -1);
    luminosidade3D.add(esfera);
}

function updateInfoCards(dados) {
    if (dados) {
        document.getElementById('temperatura-atual').textContent = dados.temperatura + '°C';
        document.getElementById('umidade-atual').textContent = dados.umidade + '%';
        document.getElementById('luminosidade-atual').textContent = dados.luminosidade + ' lux';
    }
}

function animate() {
    requestAnimationFrame(animate);
    
    if (temperatura3D) {
        temperatura3D.rotation.y += 0.002;
    }
    if (umidade3D) {
        umidade3D.rotation.y += 0.001;
    }
    if (luminosidade3D) {
        luminosidade3D.rotation.y += 0.003;
    }
    
    for (let i = 0; i < dadosArray.length; i++) {
        const child = temperatura3D?.children[i];
        if (child) {
            child.position.y = (Math.sin(Date.now() * 0.001 + i * 0.5) * 0.1) + dadosArray[i].temperatura/10;
        }
        
        const childUmi = umidade3D?.children[i];
        if (childUmi) {
            childUmi.position.y = (Math.sin(Date.now() * 0.002 + i * 0.3) * 0.05) + dadosArray[i].umidade/10;
        }
    }
    
    controls.update();
    renderer.render(scene, camera);
}

function onWindowResize() {
    camera.aspect = window.innerWidth / (window.innerHeight * 0.5);
    camera.updateProjectionMatrix();
    renderer.setSize(document.getElementById('dashboard3D').clientWidth, 400);
} 