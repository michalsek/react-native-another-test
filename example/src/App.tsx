import { useState, useEffect } from 'react';
import { StyleSheet, View, Text, TextInput } from 'react-native';
import { multiply } from 'react-native-another-test';

export default function App() {
  const [numA, setNumA] = useState<number>(0);
  const [numB, setNumB] = useState<number>(0);
  const [result, setResult] = useState<number | undefined>();

  useEffect(() => {
    setResult(multiply(numA, numB));
  }, [numA, numB]);

  return (
    <View style={styles.container}>
      <View>
        <View style={styles.row}>
          <TextInput
            keyboardType="numeric"
            placeholder="Number A"
            onChangeText={(text) => setNumA(parseInt(text, 10))}
            style={styles.textInput}
          />
        </View>
        <View style={styles.row}>
          <TextInput
            keyboardType="numeric"
            placeholder="Number B"
            onChangeText={(text) => setNumB(parseInt(text, 10))}
            style={styles.textInput}
          />
        </View>
      </View>
      <Text>Result: {result}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    padding: 24,
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
  row: {
    flexDirection: 'row',
    width: '100%',
    marginBottom: 16,
  },
  textInput: {
    flex: 1,
    borderWidth: 1,
    borderColor: 'black',
    height: 40,
    width: '100%',
    padding: 12,
  },
});
