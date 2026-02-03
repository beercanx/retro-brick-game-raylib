plugins {
    id("com.android.application") version "9.0.0"
}

repositories {
    google()
    mavenCentral()
}

buildscript {

    // Review these on each update of the AGP (com.android.application)
    gradle.extra["securityBoms"] = listOf(
        "io.netty:netty-bom:4.2.9.Final",
    )
    gradle.extra["securityPatches"] = listOf(
        "org.apache.httpcomponents:httpmime:4.5.14",
        "org.apache.httpcomponents:httpclient:4.5.14",
        "org.apache.commons:commons-lang3:3.18.0",
        "com.google.protobuf:protobuf-java:3.25.5",
        "com.google.protobuf:protobuf-kotlin:3.25.5",
        "org.jdom:jdom2:2.0.6.1",
        "org.bitbucket.b_c:jose4j:0.9.6",
    )

    // Handles the patching of the Android Gradle Plugin
    dependencies {
        for (securityBom in gradle.extra["securityBoms"] as List<*>) {
            classpath(platform(securityBom!!))
        }
        constraints {
            for (securityPatch in gradle.extra["securityPatches"] as List<*>) {
                classpath(securityPatch!!)
            }
        }
    }
}

configurations.named { it.startsWith("_internal-unified-test-platform") }.configureEach {
    // Handles the patching of the Android UTP (Unified Test Platform)
    dependencies {
        for (securityBom in gradle.extra["securityBoms"] as List<*>) {
            add(name, platform(securityBom!!))
        }
        constraints {
            for (securityPatch in gradle.extra["securityPatches"] as List<*>) {
                add(name, securityPatch!!)
            }
        }
    }
}

java {
    toolchain {
        languageVersion.set(JavaLanguageVersion.of(11))
    }
}

android {
    compileSdk = 35
    namespace = "uk.co.baconi.rbg"
    sourceSets.named("main") {
        assets {
            srcDir("${project.rootDir}/assets")
        }
    }
    buildFeatures {
        buildConfig = true
    }
    defaultConfig {
        minSdk = 26
        targetSdk = 35
        versionCode = 5
        versionName = "0.0.5"
        externalNativeBuild {
            cmake {
                arguments += listOf("-DPLATFORM=Android")
                targets += listOf("retro_brick_game")
            }
        }
    }
    externalNativeBuild {
        cmake {
            path = file("CMakeLists.txt")
        }
    }
}
