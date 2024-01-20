#version 330 core
out vec4 fragColor;

in vec3 FragPos;
in vec3 Normal;
in vec3 ViewDir;
in vec2 uv;

uniform sampler2D texture0;
uniform vec3 lightPosition;
uniform vec3 lightColor;  
uniform vec3 objectColor;
uniform float ambientStrength;

void main()
{
    // Calculate lighting
    vec3 lightDirection = normalize(lightPosition - FragPos);
    float diff = max(dot(Normal, lightDirection), 0.0);

    // Ambient lighting;
    vec3 ambient = ambientStrength * lightColor * objectColor;


    // Diffuse Lighting
    vec3 diffuse = diff * lightColor * objectColor;

    // Specular reflection
     float spec = pow(max(dot(reflect(-lightDirection, Normal), ViewDir), 0.0), 32.0);
    vec3 specular = spec * lightColor;

    // Sample texture
    vec4 textureColor = texture(texture0, uv);

    // Combine texture color with lighting
    vec3 result = (ambient + diffuse + specular) * textureColor.rgb;

    fragColor = vec4(result, 1.0);
}
