plugins {
    id("com.android.application") version "8.13.2"
}

repositories {
    google()
    mavenCentral()
}

buildscript {
    dependencies {
        // Security patching the Android Gradle Plugin in the eyes of the GitHub Dependency Graph.
        constraints {
            classpath("org.apache.httpcomponents:httpclient:4.5.14")
            classpath("org.apache.commons:commons-compress:1.27.1")
            classpath("com.google.protobuf:protobuf-java:3.25.5")
            classpath("com.google.protobuf:protobuf-kotlin:3.25.5")
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
